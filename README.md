# CADDRESS

A plugin to get memory address of ArrayBuffer

# Example

```javascript
const caddr = require('caddress')

const buffer = Buffer.from('abc')

const addrBuffer = caddr.get(buffer.buffer)

console.log(Buffer.from(addrBuffer).toString('hex')) // print memory address
```
