# EVE

This project aims to simulate basic lifeforms evolving and getting smarter, in a simplified manner.

## Development

### Setup

1. Install cmake & [Catch2](https://github.com/catchorg/Catch2) on your OS
2. Clone this repository:  
   HTTPS: ```git clone https://github.com/Xerus2000/eve```  
   SSH: ```git clone git@github.com:Xerus2000/eve.git```
3. Build 'eve' via CLion so that all tasks become available for running

### Structure

All production code goes into [src], separated into model, view and controller.  
[test] contains the tests and mirrors the source file structure.

### MVC

To stress the Model-View-Controller architecture, the folder structure within `src` and `test` is divided into `model`, `view` and `controller`.

### Classes and Inheritance

The folder structure should represent classes and inheritance.

Therefore,

- every class belongs in it's own folder with the same name
- every sub-class belongs within it's parent folder.

Thus, as of currently we have the following directory tree:

    object
    ├── entity
    │   ├── food
    │   └── individual
    │       ├── species1
    │       ├── species2
    │       └── ...
    └── obstacle

Representing the following Inheritance Diagram:

            Object
              │
       +------+------+
    Obstacle       Entity
                     │
              +------+------+
              Food      Individual
                            │
                     +------+------+
                    Sp1    Sp2    ...

## Testing

We use [Catch2](https://github.com/catchorg/Catch2) for testing.

The tests should be in [BDD style](https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#bdd-style), except for simple functions & data structures where it is usually more appropriate to use [test cases and sections](https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#test-cases-and-sections).

## Git Guidelines

Commit messages use the type-scope format as seen in [Karma Runner](http://karma-runner.github.io/4.0/dev/git-commit-msg.html).

Please save this git hook as *commit-msg* into *.git/hooks/* to automatically enforce the style: [commit-msg](https://www.notion.so/65a89aab035d4315bca4f2c68647fb45#4f25ab81102444bcbaba77e945712add)