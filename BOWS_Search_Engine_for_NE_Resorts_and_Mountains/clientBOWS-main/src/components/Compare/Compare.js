// Resort component 
import React, { useEffect, useState } from 'react'
import { Link, useNavigate } from 'react-router-dom';
// Bootstrap
import 'bootstrap/dist/css/bootstrap.min.css';
import { Dropdown, Table } from 'react-bootstrap';
// BOWS API
import { getResortsData } from '../Resort/data/bowsAPI';

const SortBy = () => {
    return (
        <div className="sortBy">
            <Dropdown>
                <label className="lblSortBy">SortBy: </label>
                <Dropdown.Toggle variant="light" id="dropdown-basic">
                    Select
                </Dropdown.Toggle>
                <Dropdown.Menu>
                    <Dropdown.Item href="#">Distance</Dropdown.Item>
                    <Dropdown.Item href="#">Price</Dropdown.Item>
                    <Dropdown.Item href="#">Review</Dropdown.Item>
                </Dropdown.Menu>
            </Dropdown>
        </div>
    )
};

const ResortList = () => {
    // Pull all resorts from database
    const navigate = useNavigate();
    var listResorts;
    const [resortData, setResortData] = useState(null);
    const getData = async () => {
        const navigateTo = (resort) => {
            navigate('/resort', { state: { resort } });
        }
        const test = () => { console.log("TEST"); }
        try {
            const data = await getResortsData();
            console.log(data);
            listResorts = data.map((r) => (
                <tr key={r.name}>
                    <td> <b>{r.name}</b ></td>
                    <td>{r.location.city}</td>
                    <td>{r.description}</td>
                    <td>{r.reviews.rating}</td>
                    <td>${r.price.ticket.weekdayFull}</td>
                    <td><button class="btn btn-primary" onClick={navigateTo.bind(null, r)}>View</button></td>
                </tr >
            ));
            setResortData(listResorts);
        } catch (error) {
            console.log(error);
        }

    };
    useEffect(() => {
        getData();
    }, [])

    return (
        <Table striped bordered hover>
            <thead>
                <tr>
                    <th>Name</th>
                    <th>City</th>
                    <th>Description</th>
                    <th>Rating</th>
                    <th>Price</th>
                    <th>Select</th>
                </tr>
            </thead>
            {
                resortData !== null ? (
                    <tbody>
                        {resortData}
                    </tbody>
                ) : null
            }
        </Table>
    )
};

export { SortBy, ResortList }