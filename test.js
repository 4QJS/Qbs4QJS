/* global FileInfo */

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

const tests = [
  "FileInfo.baseName('/home/konsumer/test.txt') === 'test'",
  "FileInfo.baseName('C:/windows/test.txt') === 'test'"

]

for (const test of tests) {
  const f = Function(`return ${test}`)
  console.log('\u001b[0m', test, f() ? '\u001b[32m✓' : '\u001b[31m✗', '\u001b[0m')
}
