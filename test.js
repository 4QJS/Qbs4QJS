/* global BinaryFile */
const f1 = new BinaryFile('test.bin')
console.log('Full Path:', f1.filePath())

try {
  f1.open(BinaryFile.ReadOnly)
  console.log('Contents:', f1.readAll())
} catch (e) {
  console.error('Error reading file. (thrown in JS.)', e.message)
}

/* global Environment */
try {
  // should not work
  const env = new Environment()
  console.log(env)
} catch (e) {
  // console.log('Your Environment:')
  // console.log(JSON.stringify(Environment.currentEnv(), null, 2))
  console.log('TEST var:', Environment.getEnv('TEST'))
}

/* global File */
console.log(File.lastModified('README.md'))
console.log(JSON.stringify(File.directoryEntries('.'), null, 2))

/* global FileInfo */
console.log(FileInfo.joinPaths(['cool', 'story', 'bro.txt']))

/* global Process */
const ls = new Process()
ls.start('ls', ['-al', '/tmp/'])
ls.waitForFinished()
console.log('Exit status:', ls.exitCode())
console.log(ls.readStdOut())
ls.close()

/* global TemporaryDir */
const t = new TemporaryDir()
console.log(t.path())

/* global TextFile */
const f2 = new TextFile('./README.md')
try {
  f2.open(BinaryFile.ReadOnly)
  console.log('Contents:', f2.readAll())
} catch (e) {
  console.error('Error reading file. (thrown in JS.)', e.message)
}
