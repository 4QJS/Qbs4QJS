// this is my very simple testing framework
const red = s => `\u001b[31m${s}\u001b[0m`
const green = s => `\u001b[32m${s}\u001b[0m`
const yellow = s => `\u001b[33m${s}\u001b[0m`

const test = function (title, underTest) {
  try {
    underTest()
    console.log('\t', green(title))
  } catch (e) {
    console.error('\t', red(`${title} : ${e.message}`))
    throw (e)
  }
}

/* global BinaryFile */
console.log(yellow('BinaryFile'))
test('should throw Error on missing file, on read', () => {
  try {
    const f1 = new BinaryFile('bad.bin', BinaryFile.ReadOnly)
    throw (new Error('No error.'))
  } catch (e) {
    if (e.message !== 'No such file or directory') {
      throw (new Error(`Wrong error: ${e.message}`))
    }
  }
})

test('should be able to write a file', () => {
  const f1 = new BinaryFile('./good.bin', BinaryFile.WriteOnly)
  f1.write('o hai!')
})

/* global Environment */
console.log(yellow('Environment'))
test('should throw if user tries to use it as a class', () => {
  try {
    const env = new Environment()
    throw (new Error('No error.'))
  } catch (e) {
    if (e.message !== 'Type error') {
      throw (new Error('wrong error.'))
    }
  }
})

test('should be able to get env-var TEST', () => {
  const t = Environment.getEnv('TEST')
  if (t !== 'QJS rox!') {
    throw (new Error('Env-var not set correctly.'))
  }
})

/* global File */
console.log(yellow('File'))
test('should be able to get lastModified', () => {
  if (!File.lastModified('README.md')) {
    throw (new Error('Could not.'))
  }
})

/* global FileInfo */
console.log(yellow('FileInfo'))
test('should be able to get joinPaths', () => {
  if (FileInfo.joinPaths('cool', 'story', 'bro.txt') !== 'cool/story/bro.txt') {
    throw (new Error('Could not.'))
  }
})

/* global Process */
console.log(yellow('Process'))
test('should be able to run ls', () => {
  const ls = new Process()
  ls.start('ls', ['-al', '/tmp/'])
  ls.waitForFinished()
  const c = ls.exitCode()
  const o = ls.readStdOut()
  ls.close()
  if (c) {
    throw (new Error(`Exit status: ${c}`))
  }
  if (!o || o === '') {
    throw (new Error('Could not.'))
  }
})

/* global TemporaryDir */
console.log(yellow('TemporaryDir'))
let tempDir
test('should be able to create a temporary dir', () => {
  tempDir = new TemporaryDir()
  const p = tempDir.path()
  if (!p || p === '') {
    throw (new Error('Could not.'))
  }
})

test('should be able to delete the temporary dir', () => {
  const ok = tempDir.remove()
  if (!ok) {
    throw (new Error('Could not.'))
  }
})

/* global TextFile */
console.log(yellow('TextFile'))
test('should be able to read a file', () => {
  const f1 = new TextFile('./README.md')
  const c = f1.readAll()
  if (!c || c === '' || c.indexOf('Qbs') === -1) {
    throw (new Error('Could not.'))
  }
})

test('should throw Error on missing file, on read', () => {
  try {
    const f1 = new BinaryFile('bad.txt')
    throw (new Error('No error.'))
  } catch (e) {
    if (e.message !== 'No such file or directory') {
      throw (new Error(`Wrong error: ${e.message}`))
    }
  }
})

test('should be able to write a file', () => {
  const f1 = new TextFile('./good.txt', TextFile.WriteOnly)
  f1.write('o hai!')
})
