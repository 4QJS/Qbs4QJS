# WIP

This is not at all ready for use, I'm just putting it together.

# Qbs4QJS

I find [Qbs services](https://doc.qt.io/qbs/list-of-builtin-services.html) useful in a javascript-context, but they are made for `QScriptEngine`, which is deprecated.

I wanted to be able to expose all the same services to `QJSEngine`, so I copied their API using regular Qt5 stuff.

You can have a look at the [original Qbs source](https://code.qt.io/cgit/qbs/qbs.git/tree/src/lib/corelib/jsextensions/). This project should mostly follow the same shape, and everything basically work the same.

> **TODO**: Work out Qt-version support-matrix. It should be easy to tell if people can use this in their thing.

### caveats

#### [variable argument length](https://github.com/konsumer/Qbs4QJS/issues/2)

Anything with a dynamic number of arguments (like `FileInfo::joinPaths`) uses an array, so it will be like this, instead:

```js
FileInfo.joinPaths(['one', 'two', 'three'])
```

#### [constructors don't throw](https://github.com/konsumer/Qbs4QJS/issues/4)

Class constructors don't throw. An example is `BinaryFile`, there is a seperate `open` method, so the constructor doesn't throw an error.


I may eventually figure out how to make it work more like the original.

### usage

> **TODO**: look into the best way to add this to user's projects & publish the library.


You can see an example program that uses all the services in [main.cpp](./main.cpp).

You can just include the headers you need, and they only depend on Qt.


> **TODO**: Put basic import example, from main.cpp, here


### development

If you want to work on it, you'll need qt & qbs installed.

You can build a test program, and run the javascript test with this command:

```sh
qbs run -- test.js
```

I also made a little package.json, so you can run things, from node:

```sh
npm i         # install tools from npm
npm test      # build and run against text.js
npm run build # build tools & library
npm run lint  # check & fix against [standard code format](https://standardjs.com/)
```

### completion

Here are the Qbs APIs that are implemented:

- [X] BinaryFile
- [X] Environment
- [X] File
- [X] FileInfo
- [X] Process
- [X] TemporaryDir
- [X] TextFile

#### maybe not

Here are the other ones, which I might drop:

- [ ] PropertyList - darwin-only. maybe use [qtplist](https://github.com/reillywatson/qtplist)
- [ ] Utilities - not really using this anywhere
- [ ] Xml -not really using this anywhere


#### more

* Ideally, each one needs to have every method tested in the full support matrix (every version of QT that Qbs supports.) This is not completed.
* I'd also like to add "extras" to just about all of these. Qbs JS service API is the baseline, but I intend to include lots more helpers that are related. `QFileInfo` has lots of useful things, as does `QFile` and `QDir`.
* I need to go through and verify I am using references & `const` wherever possible. I think I am under-utilizing them, and they would be better.