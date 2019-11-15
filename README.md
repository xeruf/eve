
# EVE

[![experimental](http://badges.github.io/stability-badges/dist/experimental.svg)](http://github.com/badges/stability-badges)[![unstable](http://badges.github.io/stability-badges/dist/unstable.svg)](http://github.com/badges/stability-badges)

##### Simulate simple, artificial lifeforms as they learn and evolve

----

#### Table of Content

1. Setup
2. Description
3. Collaboration
4. About

----

### Setup

* **Requirements:** Build tools: `cmake`, `make`, an ISO C++17 Compiler
* **Download**: ``` git clone https://github.com/Xerus2000/eve```
* **Build:** Run `cmake` and then `make`
* **Run:** Start the simulation by executing `eve`

----

### Description

This project aims to simulate a two-dimensional environment with basic individuals; circles with a set of extremities (limbs, mouths, eyes). They shall eat randomly generated food and evolve through breeding. Throughout their life, individuals shall become smarter through reinforcement learning based on their own perception.

----

### Collaboration (through pull requests)

* **Pull requests:** One reviewer required, always [squash and merge](https://help.github.com/en/github/collaborating-with-issues-and-pull-requests/about-pull-request-merges#squash-and-merge-your-pull-request-commits)

* **Commit guidelines:** see [Karma Runner](http://karma-runner.github.io/4.0/dev/git-commit-msg.html)
  * `git config core.hooksPath .dev/githooks` for style enforcement
* **Architecture:** Model-View-Controller
  * Code is divided into `src/` and `test/`, with sub-folders `model/`, `view/` and `controller/` each

* **Testing framework:** [Catch2](https://github.com/catchorg/Catch2), Using Behaviour-Driven Development (see [Catch2: BDD](https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#bdd-style))

----

### About

**Authors**: [Xerus2000](https://github.com/Xerus2000), [AtomToast](https://github.com/AtomToast), [szudemj](https://github.com/szudemj), [anarchuser](https://github.com/anarchuser)

**Company**: [CODE University of Applied Sciences](https://code.berlin/en/)