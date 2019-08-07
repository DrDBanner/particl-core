// Copyright (c) 2018-2019 The Particl Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef PARTICL_SMSG_NET_H
#define PARTICL_SMSG_NET_H

#include <sync.h>

const uint32_t SMSG_RCVCOUNT_REDUCE = 200;

class PeerBucket
{
public:
    PeerBucket(uint32_t active, uint32_t hash) : m_active(active), m_hash(hash) {};
    uint32_t m_active;
    uint32_t m_hash;
};

class SecMsgNode
{
public:
    CCriticalSection cs_smsg_net;
    int64_t lastSeen = 0;
    int64_t lastMatched = 0;
    int64_t ignoreUntil = 0;
    uint32_t nWakeCounter = 0;
    uint16_t misbehaving = 0;
    uint16_t m_num_want_sent = 0;
    uint16_t m_receive_counter = 0;
    uint16_t m_ignored_counter = 0;
    bool fEnabled = false;
    std::map<int64_t, PeerBucket> m_buckets;

    void DecSmsgMisbehaving() {
        LOCK(cs_smsg_net);
        if (m_receive_counter < SMSG_RCVCOUNT_REDUCE) {
            m_receive_counter = 0;
        } else {
            m_receive_counter -= SMSG_RCVCOUNT_REDUCE;
        }
    }
};

#endif // PARTICL_SMSG_NET_H
