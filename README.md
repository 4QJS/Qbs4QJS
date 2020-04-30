# WIP

This is not at all ready for use, I'm just putting it together.

# Qbs4QJS

I find [Qbs services](https://doc.qt.io/qbs/list-of-builtin-services.html) useful in a javascript-context, but they are made for `QScriptEngine`, which is deprecated.

I wanted to be able to expose all the same services to `QJSEngine`, so I copied their API using regular Qt5 stuff.

You can have a look at the [original Qbs source](https://code.qt.io/cgit/qbs/qbs.git/tree/src/lib/corelib/jsextensions/). This project should mostly follow the same shape, and everything basically work the same.

### usage

> **TODO**: look into the best way to add this to user's projects & publish the library.

You can see an example program that uses all the services in [main.cpp](./main.cpp).

You can just include the headers you need, they only depend on Qt, and not each other.

Use it with `QJSEngine` or `QQmlEngine`.


```cpp
#include <Qbs4QJS/binaryfile>
#include <Qbs4QJS/environment>
#include <Qbs4QJS/file>
#include <Qbs4QJS/fileinfo>
#include <Qbs4QJS/process>
#include <Qbs4QJS/temporarydir>
#include <Qbs4QJS/textfile>

// then later in your app:

QJSEngine jsEngine;

Qbs4QJS::BinaryFile sfbin(&jsEngine);
Qbs4QJS::Environment senv(&jsEngine);
Qbs4QJS::File sfs(&jsEngine);
Qbs4QJS::FileInfo sfi(&jsEngine);
Qbs4QJS::Process sps(&jsEngine);
Qbs4QJS::TemporaryDir stmp(&jsEngine);
Qbs4QJS::TextFile sftxt(&jsEngine);
```

There is an optional 2nd param that allows you to name it something else, in JS-space:

```cpp
Qbs4QJS::FileInfo sfi(&jsEngine, "MyCoolFileInfo");
```


### supported Qt

These versions have been tested:

* `5.14.2`


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

- [ ] PropertyList - Qbs version was darwin-only. maybe use [qtplist](https://github.com/reillywatson/qtplist)?
- [ ] Utilities - not really using this anywhere, and they are very specialized.
- [ ] Xml - not really using this anywhere, and it seems a bit complicated.


#### more

* Ideally, each one needs to have every method tested in the full support matrix (every version of Qt that this lib will work with.) This is not completed.
* I'd also like to add "extras" to just about all of these. Qbs JS service API is the baseline, but I intend to include lots more helpers that are related. `QFileInfo` has lots of useful things, as does `QFile` and `QDir`.
* I need to go through and verify I am using references & `const` wherever possible. I think I am under-utilizing them, and they would be better.
* Additional helpful utils could be added: `ZipFile`, `Crypto` (for hashing and encrypt/decrypt), [`fetch`](https://developer.mozilla.org/en-US/docs/Web/API/Fetch_API/Using_Fetch), maybe some way to use npm modules.