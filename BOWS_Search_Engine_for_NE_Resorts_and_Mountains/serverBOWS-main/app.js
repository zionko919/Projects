// BOWS UML GUI2 project
// Authors: Danny Lisamay, Taylor Youth, Sean Ko

// .env
require('dotenv').config();
// Express js
const express = require("express");
// MongoDB
const mongoose = require("mongoose");
const app = express();
// CORS
const cors = require('cors');

// Public folder used for css, and other files on local host.
app.use(express.static("public"));
//app.use(express.urlencoded()); //Parse URL-encoded bodies

// Enable All CORS Requests)
app.use(cors());

// Connent mongoDB using .env for enviroment varibles
mongoose.connect(process.env.MONGODB_URL ||
  "mongodb+srv://" + process.env.DB_USER + ":" + process.env.DB_PASS + "@cluster0.k5s63.mongodb.net/BOWS?retryWrites=true&w=majority",
  { useNewUrlParser: true, useUnifiedTopology: true });
mongoose.set("useCreateIndex", true);

// Schema
const resortSchema = new mongoose.Schema({
  name: String,
  location: Object,
  price: Object
});

const resort = mongoose.model('resort', resortSchema);

//RESTFUL API
//chainned route handlers
//GET
//GET all articles.
app.route("/")
  .get((req, res) => {
    resort.find((err, resort) => {
      if (!err) {
        res.send(resort);
      } else {
        res.send(err);
      }
    });
  })

  //PUT/POST
  .post((req, res) => {
    const newResort = new resort({
      name: req.body.name,
      location: req.body.location,
      price: req.body.price
    });
    newResort.save();
  })
  //DELETE
  //DELETE specific article
  //Please dont use this taylor or sean.
  .delete((req, res) => {
    resort.deleteMany((err) => {
      if (!err) {
        res.send("Deleted all resorts");
      } else {
        res.send(err);
      }
    });
  });

//chainned route handlers
//GET specific resort
app.route("/:resortName")
  .get((req, res) => {
    resort.findOne({ name: req.params.resortName }, (err, foundResort) => {
      if (foundResort) {
        res.send(foundResort);
      } else {
        res.send("No resort with that name found.");
      }
    });
  })
  //PUT/POST specific resort
  .put((req, res) => {
    resort.updateOne(
      { name: req.params.resortName },
      {
        name: req.body.name,
        location: req.body.location,
        price: req.body.price
      },
      (err) => {
        if (!err) {
          res.send("Updated resort.")
        } else {
          res.send(err);
        }
      }
    )
  })
  //UPDATE specific resort
  .patch((req, res) => {
    resort.updateOne(
      { name: req.params.resortName },
      { $set: req.body },
      (err) => {
        if (!err) {
          res.send("Updated resort.")
        } else {
          res.send(err);
        }
      }
    );
  })
  //DELETE specific resort
  .delete((req, res) => {
    resort.deleteOne(
      { name: req.params.resortName },
      (err) => {
        if (!err) {
          res.send("Deleted resort.")
        } else {
          res.send(err);
        }
      }
    );
  });

// Local port 4000 used for testing.
const port = process.env.PORT || 4000;
app.listen(port, () => {
  console.log(`BOWS app listening at http://localhost:${port}`)
});
