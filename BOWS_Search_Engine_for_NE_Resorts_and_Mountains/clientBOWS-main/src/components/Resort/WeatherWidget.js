// Resort component 
import React, { useEffect, useState } from 'react'
// Bootstrap
import 'bootstrap/dist/css/bootstrap.min.css';
import { Container, Row } from 'react-bootstrap';
import { getWeatherData } from './data/weatherAPI'
// days array
const days = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
// date 
const date = new Date();
// current day
const day1 = days[date.getDay()];
// 2 days after current day
const day2 = days[(date.getDay() + 1) % 7];
const day3 = days[(date.getDay() + 2) % 7];

const WeatherWidget = (city) => {
    // weather Data
    // list data is unix UTC
    const [weatherdata, setWeatherData] = useState(null);
    const getData = async () => {
        try {
            const data = await getWeatherData(city);
            setWeatherData(data);
        } catch (error) {
            console.log(error);
        }
    }
    useEffect(() => {
        getData();
    }, [])

    return (<div>
        <h6>Weather Forcast</h6>
        {
            weatherdata !== null ? (
                <div>
                    <Container>
                        <Row className="flex-nowrap">
                            <div className="weatherBox">
                                {day1}<br />
                                {weatherdata.list[0].main.temp}<br />
                                <img src={'https://openweathermap.org/img/wn/' + weatherdata.list[0].weather[0].icon + '@2x.png'} alt="weatherBox0" /><br />
                                {weatherdata.list[0].weather[0].description}
                            </div>
                            <div className="weatherBox">
                                {day2} < br />
                                {weatherdata.list[9].main.temp} < br />
                                <img src={'https://openweathermap.org/img/wn/' + weatherdata.list[8].weather[0].icon + '@2x.png'} alt="weatherBox1" /><br />
                                {weatherdata.list[9].weather[0].description}
                            </div>
                            <div className="weatherBox">
                                {day3} < br />
                                {weatherdata.list[16].main.temp} < br />
                                <img src={'https://openweathermap.org/img/wn/' + weatherdata.list[16].weather[0].icon + '@2x.png'} alt="weatherBox2" /><br />
                                {weatherdata.list[16].weather[0].description}
                            </div>
                        </Row>
                    </Container>
                </div>
            ) : null
        }
    </div>);
}
export default WeatherWidget;
