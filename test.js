/* global BinaryFile */

const b1 = new BinaryFile('test.bin', BinaryFile.ReadWrite)
console.log(b1.filePath())
console.log(`${b1.atEof() ? 'At' : 'Not at'} end of file.`)
