/* global BinaryFile */

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
