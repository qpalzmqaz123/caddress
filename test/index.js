'use strict'

const caddr = require('..')

let buffer = new Uint8Array([1, 2, 3, 4, 5, 6, 7])

let addr = caddr.get(buffer.buffer)

console.log(Buffer.from(addr).toString('hex'))
