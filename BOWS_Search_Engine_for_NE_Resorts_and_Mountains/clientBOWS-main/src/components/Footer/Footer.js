// Footer component dynamically update year 
import React from "react";
import { Container } from 'react-bootstrap';

const footer = () => {
    const currentYear = new Date().getFullYear();
    return (
        <footer>
            <Container>
                Copyright © {currentYear}
            </Container>
        </footer>
    );
};

// Default return for footer component 
export default footer