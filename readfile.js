const fs = require("fs");

function countWords(string) {
  let words = string.split(" ");
  return words.length;
}

function readFromFile(file) {
  return new Promise(function (res, rej) {
    fs.readFile(file, "utf-8", function (err, data) {
      if (err) rej(err);
      else res(data);
    });
  });
}

function writeToFile(file, newData) {
  return new Promise(function (res, rej) {
    console.log("We're here bitches!");
    fs.writeFile(file, newData, function (err) {
      if (err) rej(err);
      else {
        console.log("We're here bitches - again!!!");
        res();
      }
    });
  });
}

fileName = "file.txt";
readCounter = 0;

readFromFile(fileName)
  .then(function (data) {
    console.log(`File Read Happened", ${(readCounter += 1)}`);
    console.log(data);
    console.log("Number of words: ", countWords(data));
    return writeToFile(
      fileName,
      "This is some new data added on to the previously present contents"
    );
  })
  .then(function () {
    console.log("File has been written upon.");
    console.log("File has been saved!");
    return readFromFile(fileName);
  })
  .then(function (data) {
    console.log(`File Read Happened", ${(readCounter += 1)}`);
    console.log(data);
    console.log("Number of words: ", countWords(data));
  })
  .catch(function (err) {
    console.error(err);
  });