# WIP

This is not at all ready for use, I'm just putting it together.

# Qbs4QJS

I find [Qbs services](https://doc.qt.io/qbs/list-of-builtin-services.html) useful in a javascript-context, but they are made for `QScriptEngine`, which is deprecated.

I wanted to be able to expose all the same services to `QJSEngine`, so I copied their API using regular Qt5 stuff.

You can have a look at the [original Qbs source](https://code.qt.io/cgit/qbs/qbs.git/tree/src/lib/corelib/jsextensions/). This project should mostly follow the same shape, and everything basically work the same.

### caveats

Anything with a dynamic number of arguments (like `FileInfo::joinPaths`) uses an array, so it will be like this, instead:

```js
const fi = new FileInfo()
fi.joinPaths(['one', 'two', 'three'])
```

I may eventually figure out how to make it work the other way.

### usage

You can see an example program that uses all the services in [main.cpp](./main.cpp).


> **TODO**: look into the best way to add this to user's projects & publish the library.
> **TODO**: Put basic import form maon.cpp here


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
npm run lint  # check & fix against stabndard code format
```

### complete

Not all the services are complete. Ideally, each one needs to have every method tested in the full support matrix (every version of QT that Qbs supports.)

- [ ] BinaryFile
- [ ] Environment
- [ ] File
- [ ] FileInfo
- [ ] General
- [ ] Process
- [ ] PropertyList
- [ ] TemporaryDir
- [ ] TextFile
- [ ] Utilities
- [ ] Xml
