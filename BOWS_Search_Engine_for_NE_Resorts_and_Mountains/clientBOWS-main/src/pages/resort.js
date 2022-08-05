// Resort component 
import React from 'react'
// Bootstrap
import 'bootstrap/dist/css/bootstrap.min.css';
import { Container, Row, Col } from 'react-bootstrap';
import { ResortInfo, ResortInfoTabBox1, ResortInfoTabBox2 } from "../components/Resort/Resort"

const Resort = () => {
    return (
        <div className="box" >
            <Container fluid>
                <Row>
                    <Col xs={12} md={6} lg={4}>
                        <ResortInfo />
                    </Col>
                    <Col xs={12} md={6} lg={8}>
                        <ResortInfoTabBox1 />
                        <ResortInfoTabBox2 />
                    </Col>
                </Row>
            </Container>
        </div>
    );
};
export default Resort