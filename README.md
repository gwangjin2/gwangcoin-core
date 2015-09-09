gwangcoin integration/staging tree
================================

http://www.gwangmoney.money

Copyright (c) 2009-2014 Bitcoin Developers
Copyright (c) 2011-2014 Litecoin Developers
Copyright (c) 2014-2015 Gwangcoin Developers
Copyright (c) 2015-     gwcoin Developers

광진마을화폐는 ?
----------------

광진마을화폐은 광진구민과 협동사회경제 조직을 기반시스템으로 수원시민화폐(gwangcoin)기반으로 만들어 졌으며 주요특징으로

  -  블록생성시간: 1분
  -  마이닝 없음(초기 블럭에서 10억코인 생성)
  -  화폐총량: 10억 코인
  -  출금확인: 5분.
  -  10블럵 이후 블록당 발행량 0 코인
  -  난위도 조절 간격(retarget difficulty) 2016 blocks

For more information, as well as an immediately useable, binary version of
the gwangmoney.com client sofware, see http://www.gwangmoney.com.

License
-------

Litecoin is released under the terms of the MIT license. See `COPYING` for more
information or see http://opensource.org/licenses/MIT.

Development process
-------------------

Developers work in their own trees, then submit pull requests when they think
their feature or bug fix is ready.

If it is a simple/trivial/non-controversial change, then one of the Gwangcoin
development team members simply pulls it.

If it is a *more complicated or potentially controversial* change, then the patch
submitter will be asked to start a discussion with the devs and community.

The patch will be accepted if there is broad consensus that it is a good thing.
Developers should expect to rework and resubmit patches if the code doesn't
match the project's coding conventions (see `doc/coding.txt`) or are
controversial.

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/yezune/gwangcoin/tags) are created
regularly to indicate new official, stable release versions of Litecoin.

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test. Please be patient and help out, and
remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write unit tests for new code, and to
submit new unit tests for old code.

Unit tests for the core code are in `src/test/`. To compile and run them:

    cd src; make -f makefile.unix test

Unit tests for the GUI code are in `src/qt/test/`. To compile and run them:

    qmake BITCOIN_QT_TEST=1 -o Makefile.test bitcoin-qt.pro
    make -f Makefile.test
    ./gwangcoin-qt_test

