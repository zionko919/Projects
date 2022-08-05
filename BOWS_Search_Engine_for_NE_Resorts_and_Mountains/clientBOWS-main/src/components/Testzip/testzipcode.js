// Resort component 
import React, { useEffect, useState } from 'react'
import axios from 'axios';
import { getResortsData } from '../Resort/data/bowsAPI';

/*


const userZipCode = "01851";
const moutainZip =  "03242";
const apikey = 'IKUQxTVThFQ5koEbehPBqbXYvfY2QUmFcdIoNCh5lNSe0GtdF9NEg8Mzh0d679Xi';
const apiDistance = `https://www.zipcodeapi.com/rest/${apikey}/distance.json/${userZipCode}/${moutainZip}/mile`;

const distance = document.querySelector("#distance")


fetch(apiDistance)
.then(response => response.json())
  .then(data => console.log(data));

function showDistance(data){
    console.log(data.distance);
    return(

      <div>
      {data.distance}
      </div>

        );
}



const resortData = [{
  name: "Nashoba",
  location: {
    zip: "01886",
    city: "Westford ",
    state: "MA"
  },
  price: {
    ticket: {
      weekdayFull: 55,
      weekdayHalf: 40,
      weekendFull: 55,
      weekendHalf: 40
    },
    rental: {
      skiBootsPole: {
        adult: 40,
        junior: 40,
        child: 40
      },
      snowboardandBoots: {
        adult: 40,
        junior: 40,
        child: 40
      },
      helmet: 10,
    }
  }
},
{
  name: "Pats Peak",
  location: {
    zip: "03242",
    city: "Henniker",
    state: "NH"
  },
  price: {
    ticket: {
      weekdayFull: 69,
      weekdayHalf: 59,
      weekendFull: 79,
      weekendHalf: 69
    },
    rental: {
      skiBootsPole: {
        adult: 40,
        junior: 36,
        child: 32
      },
      snowboardandBoots: {
        adult: 40,
        junior: 36,
        child: 32
      },
      helmet: 12,
    }
  }
}
]

const zipcodeforresort = parseInt(resortData[0].location.zip);
//used to find exact zipcode from array of resort
console.log(resortData[0].location.zip)

export default showDistance;
*/



const Test = () => {
  const [resortData, setSetData] = useState(null);
  const getData = async () => {
    try {
      const data = await getResortsData();
      setSetData(data);
    } catch (error) {
      console.log(error);
    }
  }
  useEffect(() => {
    getData();
  }, [])

  return (
    <div>
      {
        resortData !== null ? (
          <p>{resortData[0].name}</p>
        ) : null
      }
    </div>
  );
}

export default Test;