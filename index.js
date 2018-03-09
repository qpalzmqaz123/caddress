'use strict'

const binding = require('./build/Release/binding.node')

exports.get = binding.getAddress
