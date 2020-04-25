/* global BinaryFile */

const b1 = new BinaryFile('test.bin', BinaryFile.ReadOnly)
console.log(b1.filePath())

try {
  console.log(b1.read(b1.size()))
} catch (e) {
  console.error('Error reading file.', e.message)
}

console.log(b1)
