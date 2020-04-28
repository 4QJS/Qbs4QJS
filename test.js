/* global BinaryFile */

const b1 = new BinaryFile('test.bin')
console.log(b1.filePath())

try {
  b1.open(BinaryFile.ReadOnly)
  console.log(b1.read(b1.size()))
} catch (e) {
  console.error('Error reading file.', e.message)
}

console.log(b1)
