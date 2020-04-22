# WIP

This is not at all ready for use, I'm just putting it together.

# Qbs4QJS

I find [Qbs services](https://doc.qt.io/qbs/list-of-builtin-services.html) useful in a javascript-context, but they are made for `QScriptEngine`, which is deprecated.

I wanted to be able to expose all the same services to `QJSEngine`, so I copied their API using regular Qt5 stuff.

You can have a look at the [original Qbs source](https://code.qt.io/cgit/qbs/qbs.git/tree/src/lib/corelib/jsextensions/). This project should mostly follow the same shape, and everything should work the same.

### usage

You can see an example program that uses all the services in [main.cpp](./main.cpp).


> **TODO**: look into the best way to add this to user's projects & publish the library.

Add it to your project, and include it like this:

```cpp
#include <QQmlEngine>

#include <Qbs4QJS/scriptbinaryfile>
#include <Qbs4QJS/scriptenvironment>
#include <Qbs4QJS/scriptfile>
#include <Qbs4QJS/scriptfileinfo>
#include <Qbs4QJS/scriptgeneral>
#include <Qbs4QJS/scriptprocess>
#include <Qbs4QJS/scriptpropertylist>
#include <Qbs4QJS/scripttemporarydir>
#include <Qbs4QJS/scripttextfile>
#include <Qbs4QJS/scriptutilities>
#include <Qbs4QJS/scriptxml>
```

Each file correlates to a [Qbs service](https://doc.qt.io/qbs/list-of-builtin-services.html).

Next, add them to your `QJSEngine` or `QQmlEngine`:

```cpp
QQmlEngine mEngine = new QQmlEngine(this);
QJSValue globalObject = mEngine->globalObject();

ScriptBinaryFile mBinaryFile = new ScriptBinaryFile(this);
ScriptEnvironment mEnvironment = new ScriptEnvironment(this);
ScriptFile mFile = new ScriptFile(this);
ScriptFileInfo mFileInfo = new ScriptFileInfo(this);
ScriptGeneral mGeneral = new ScriptGeneral(this);
ScriptProcess mProcess = new ScriptProcess(this);
ScriptPropertyList mPropertyList = new ScriptPropertyList(this);
ScriptTemporaryDir mTemporaryDir = new ScriptTemporaryDir(this);
ScriptTextFile mTextFile = new ScriptTextFile(this);
ScriptUtilities mUtilities = new ScriptUtilities(this);
ScriptXml mXml = new ScriptXml(this);

globalObject.setProperty(QStringLiteral("BinaryFile"), mEngine->newQObject(mBinaryFile));
globalObject.setProperty(QStringLiteral("Environment"), mEngine->newQObject(mEnvironment));
globalObject.setProperty(QStringLiteral("File"), mEngine->newQObject(mFile));
globalObject.setProperty(QStringLiteral("FileInfo"), mEngine->newQObject(mFileInfo));
globalObject.setProperty(QStringLiteral("General"), mEngine->newQObject(mGeneral));
globalObject.setProperty(QStringLiteral("Process"), mEngine->newQObject(mProcess));
globalObject.setProperty(QStringLiteral("PropertyList"), mEngine->newQObject(mPropertyList));
globalObject.setProperty(QStringLiteral("TemporaryDir"), mEngine->newQObject(mTemporaryDir));
globalObject.setProperty(QStringLiteral("TextFile"), mEngine->newQObject(mTextFile));
globalObject.setProperty(QStringLiteral("Utilities"), mEngine->newQObject(mUtilities));
globalObject.setProperty(QStringLiteral("Xml"), mEngine->newQObject(mXml));
```

You don't have to include them all, and the global names don't matter, just include & name them how you want.