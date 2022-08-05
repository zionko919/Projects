import axios from 'axios';
const key = "Hs-5WN9Jm5JgROdPL165FnrvQ0ARUz9P-XDbKp36iMqTxqlhLGTH8dqeU7CEZzOzg4ym9th_5g6bSyPYFvqbgo7V7X-YRGpY_Fu-75iRjXX_DLQlip6ruyDrbUWMYHYx";

export const getYelpReview = async (c) => {
    const baseURL = "https://api.yelp.com/v3/businesses/simply-khmer-lowell-2";
    try {
        const { data } = await axios.get(baseURL);
        return data;
    } catch (error) {
        throw error;
    }
}