import React from 'react'
// Bootstrap
import 'bootstrap/dist/css/bootstrap.min.css';
import { Container, Row } from 'react-bootstrap';
import { SortBy, ResortList } from "../components/Compare/Compare";

const Compare = () => {
    return (
        <div className="box">
            <Container fluid>
                <Row>
                    <SortBy />
                </Row>
                <ResortList />
            </Container>
        </div>
    );
};

export default Compare;
