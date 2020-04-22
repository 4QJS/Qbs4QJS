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
  console.log(g)
  console.log(Object.keys(eval(g)))
  console.log('')
}

const tests = [
  "FileInfo.baseName('/home/konsumer/test.txt') === 'test'",
  "FileInfo.baseName('C:/windows/test.txt') === 'test'"

]

for (const test of tests) {
  const f = Function(`return ${test}`)
  console.log(test, f() ? '✓' : '✗')
}
