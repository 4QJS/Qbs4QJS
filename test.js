/* eslint no-eval: 0 */
/* eslint no-new-func: 0 */

const globals = [
  'BinaryFile',
  'Environment',
  'File',
  'FileInfo',
  'General',
  'Process',
  'PropertyList',
  'TemporaryDir',
  'TextFile',
  'Utilities',
  'Xml'
]

for (const g of globals) {
  console.log('\u001b[33m', g, '\u001b[0m')
  console.log('\u001b[36m', Object.keys(eval(g)).join(', '), '\u001b[0m')
  console.log()
}

const tests = {
  FileInfo: [
    "FileInfo.baseName('/home/konsumer/test.txt') === 'test'",
    "FileInfo.baseName('C:/windows/test.txt') === 'test'",
    "FileInfo.canonicalPath('/home/konsumer/test.txt') === '.'",
    "FileInfo.cleanPath('C:/Windows/../test.txt') === 'C:/test.txt'",
    "FileInfo.completeBaseName('/home/konsumer/test.txt') === 'test'",
    "FileInfo.completeSuffix('/home/konsumer/test.txt') ==='txt'",
    "FileInfo.fileName('/home/konsumer/test.txt') ==='test.txt'",
    "FileInfo.isAbsolutePath('/home/konsumer/test.txt')",
    "!FileInfo.isAbsolutePath('test.txt')",
    "FileInfo.path('/home/konsumer/test.txt') == '/home/konsumer'",
    "FileInfo.suffix('/home/konsumer/test.txt') ==='txt'"
  ]
}

for (const test of tests) {
  const f = Function(`return ${test}`)
  const v = f()
  // console.log(v)
  console.log(v ? '\u001b[32m✓' : '\u001b[31m✗', '\u001b[0m', '\u001b[0m', test)
}
