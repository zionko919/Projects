//SEE TESTZIPCODE.JS FOR TRIAL RUN AND THOUGHT PROCESS
import React, { useEffect, useState } from 'react'
//BOWS API
import { getResortsData } from '../components/Resort/data/bowsAPI';

//import Snowboarder from '../images/snowboarder.jpg'
import { Link, useNavigate } from "react-router-dom";


//variable used for user input
var userZipCode;
//pre definded zipcode for testing
const moutainZip = "03242";
// UNQIUE API KEY DONT SHOW
const apikey = 'nC8qTyVabyAPlnldpR89nTs4OmvWmdyJmGeaHoklFH71ul1StpMre3CNxOhpCOyy';
//API used by getting apikey then having the userzipcode, and then having it compare to the second zipcode which is the mountainzipcode
var apiDistance = `https://www.zipcodeapi.com/rest/${apikey}/distance.json/${userZipCode}/${moutainZip}/mile`;


/*
// this is using the API as a function to use as the textbox by grabbing the id
// thus having it fetch the data and then console logging for now the data 
const searchzipcode = (data) => {
    userZipCode = document.getElementById('searchResortInput').value;
    apiDistance = `https://www.zipcodeapi.com/rest/${apikey}/distance.json/${userZipCode}/${moutainZip}/mile`;
    fetch(apiDistance)
        .then(response => response.json())
        .then(data => console.log(data));
};
*/
const Home = () => {
    // bowsAPI used for resorts
    const navigate = useNavigate();

    const ResortListFromApi = async () => {

        var searchResortInput = document.getElementById('searchResortInput').value;
        const data = await getResortsData();
        // Find resort from backend
        // split used to remove empty spaces. 
        // ex if user types patspeak will find pats peak.
        var search_inputresult = searchResortInput.toUpperCase();
        var resortnotfound = false;

        data.forEach(resort => {
            // this is to make it so users can enter lowercase or uppercase to look at a resort
            if ((resort.name.toUpperCase().split(' ').join('') === search_inputresult.split(' ').join(''))) {
                resortnotfound = true;
                navigate('/resort', { state: { resort } });
            }
        });

        //if resort is not found, show an alert box to show the user it is not in the database
        if (!resortnotfound) {
            console.log("Resort not found");
            alert("Resort Not Found, Will make this a text box soon. ");
        }

    }
    // function used for error when invalid input text and user clicks enter
    const enterPressed = event => {
        if (event.keyCode === 13) {
            ResortListFromApi();
        }
    };
    return (
        <div>
            <div className="aboutme">
                <p className="homepage">
                    Please enter a resort you want to search for down below!
                </p>
            </div>
            <div className="background">
                <div className="searchbar">

                    <input type="text" id="searchResortInput" className="searchbar" placeholder="Please enter your zipcode or a Resort name" onKeyDown={enterPressed}></input>

                    <button onClick={ResortListFromApi} className="searchbutton">SUBMIT </button>
                </div>
            </div>
        </div>
    );
};

export default Home;