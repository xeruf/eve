# EVE [![Build Status](https://travis-ci.com/Xerus2000/eve.svg?branch=master)](https://travis-ci.com/Xerus2000/eve) [![experimental](http://badges.github.io/stability-badges/dist/experimental.svg)](http://github.com/badges/stability-badges)[![unstable](http://badges.github.io/stability-badges/dist/unstable.svg)](http://github.com/badges/stability-badges)

##### Simulate simple, artificial lifeforms as they learn and evolve

----

This project aims to simulate a two-dimensional environment with basic individuals; circles with a set of extremities (limbs, mouths, eyes). They shall eat randomly generated food and evolve through breeding. Throughout their life, individuals shall become smarter through reinforcement learning based on their own perception.

----

#### Table of Contents

1. Setup
2. Collaboration
3. About

----

### Setup

* **Requirements:** Build tools: `cmake`, `make`, an ISO C++17 Compiler
  * [Catch2](https://github.com/catchorg/Catch2) for testing
* **Download**: Clone via SSH or HTTP
  * SSH: `git clone git@github.com:Xerus2000/eve.git`
  * HTTPS: `git clone https://github.com/Xerus2000/eve`
* **Build:** Run `cmake` and then `make`
* **Run:** Start the simulation by executing `eve`

#### Using JetBrains [CLion](https://www.jetbrains.com/clion/): 

* Build and run `eve` for production code and `tests` for tests
* Remove file headers auto-genreated by CLion:
  * Go to `Settings` > `Editor` > `File and Code Templates` and remove the "Created by" header from the C/C++ templates

----

### Collaboration

* **Pull requests:** One reviewer required, use [squash'n merge](https://help.github.com/en/github/collaborating-with-issues-and-pull-requests/about-pull-request-merges#squash-and-merge-your-pull-request-commits) or  [rebase'n merge](https://help.github.com/en/github/collaborating-with-issues-and-pull-requests/about-pull-request-merges#rebase-and-merge-your-pull-request-commits) as appropriate

* **Commit guidelines:** see [Karma Runner](http://karma-runner.github.io/4.0/dev/git-commit-msg.html)
  * `git config core.hooksPath .dev/githooks` for style enforcement
* **Architecture:** Model-View-Controller
  * The architecture is mirrored in the file structure as `model/`, `view/` and `controller/` sub folders
* Production code belongs to `/src/`, testing code to /`test`
    * The folder structure of `/src/` should mirror the one of `/test/` 
  * The folder structure should further follow the inheritance tree, with the base class being in `model`
  
* **Testing framework:** [Catch2](https://github.com/catchorg/Catch2), Using TDD and BDD as appropriate (see [Catch2: BDD](https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#bdd-style))

----

### About

**Authors**: [Xerus2000](https://github.com/Xerus2000), [AtomToast](https://github.com/AtomToast), [szudemj](https://github.com/szudemj), [anarchuser](https://github.com/anarchuser)