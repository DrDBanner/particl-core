Particl Core integration/staging tree
=====================================

[![Build Status](https://travis-ci.org/particl/particl-core.svg?branch=master)](https://travis-ci.org/particl/particl-core)

https://particl.io

What is Particl?
----------------

Particl is a decentralized, open source privacy platform for trading goods and services without intermediaries. The ecosystem currently includes the digital currency PART and the Particl Marketplace application.

PART is the cryptocurrency of the Particl blockchain. It is an independent usable secure and confidential digital currency specifically designed to power a marketplace and acts as its settlement layer. It uses several security, encryption, and privacy protocols to make sure no personal information and data can be collected when transacting on the marketplace.

|Properties|Values| 
|:-------------------------|:-----------------------------------------| 
|Native blockchain|Particl| 
|Blockchain codebase|Bitcoin (latest)|
|Block Time|120 seconds| 
|Block Size|2 MB|
|Consensus Mechanism|Particl Proof-of-Stake (PPoS)|
|Privacy Protocols|Confidential Transactions (CT) and RingCT|
|Bulletproofs|:white_check_mark: yes|
|Stealth Addresses|:white_check_mark: yes|
|Ring Signatures|:white_check_mark: yes|
|Cold Staking|:white_check_mark: yes|
|Segwit|:white_check_mark: yes|
|Lightning Network|:white_check_mark: yes|
|Atomic Swaps|:white_check_mark: yes|

For more information please visit https://particl.io and https://particl.wiki. The Particl Desktop application is available in this repository https://github.com/particl/particl-desktop.

Getting Started
---------------

A new Particl wallet will need an HD master key loaded and an initial account
derived before it will be functional.

The GUI programs will guide you through the initial setup.

It is recommended to use a mnemonic passphrase.
To generate a new passphrase see the mnemonic rpc command.
Loading the new mnemonic with the extkeyimportmaster command will setup the
master HD key and first account.

To create an initial new HD master key and account from random data, start
particld or particl-qt with the parameter: -createdefaultmasterkey.

Remember to backup your passphrase and/or wallet.dat file!

License
-------

Particl Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is regularly built (see doc/build-*.md for instructions) and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/particl/particl-core/tags) are created
regularly to indicate new official, stable release versions of Particl Core.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md)
and useful hints for developers can be found in [doc/developer-notes.md](doc/developer-notes.md).

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/test), written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/test) are installed) with: `test/functional/test_runner.py`

The Travis CI system makes sure that every pull request is built for Windows, Linux, and macOS, and that unit/sanity tests are run automatically.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

