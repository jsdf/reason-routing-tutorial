const path = require('path');

module.exports = {
  entry: {
    main: './lib/js/src/index.js',
  },
  output: {
    path: path.join(__dirname, "public/build"),
    filename: '[name].js',
  },
};
