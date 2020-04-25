/* global BinaryFile */

const b1 = new BinaryFile('test.bin', BinaryFile.ReadOnly)
console.log(b1.filePath())
console.log(b1.read(b1.size()))
