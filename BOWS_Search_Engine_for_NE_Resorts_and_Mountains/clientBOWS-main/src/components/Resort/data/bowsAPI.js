//BOWS RESTful api, used for resort info
import axios from 'axios';

const bowsAPIurl = "https://bows.herokuapp.com/";

export const getResortsData = async () => {
    try {
        const response = await axios.get(bowsAPIurl);
        return response.data;
    } catch (error) {
        console.error(error);
    }
}