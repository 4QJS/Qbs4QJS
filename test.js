/* global BinaryFile */

const b1 = new BinaryFile('test.bin')
console.log('Full Path:', b1.filePath())

try {
  b1.open(BinaryFile.ReadOnly)
  console.log('Contents:', b1.read(b1.size()))
} catch (e) {
  console.error('Error reading file. (thrown in JS.)', e.message)
}

/* global Environment */
