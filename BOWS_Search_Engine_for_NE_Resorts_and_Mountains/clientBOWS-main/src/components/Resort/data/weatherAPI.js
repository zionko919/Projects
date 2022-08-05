import axios from "axios";
const key = "25d0569851c0869a01a553ee05c7ffff";
export const getWeatherData = async (city) => {
    console.log(city);
    const baseURL = "https://api.openweathermap.org/data/2.5/forecast?q=" + city + "&appid=" + key + "&units=imperial";
    try {
        const { data } = await axios.get(baseURL);
        return data;
    } catch (error) {
        throw error;
    }
}