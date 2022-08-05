import React from 'react'
import { Nav, NavLink, Bars, NavMenu, NavBtn } from './Navbar';
import Logo from '../../images/bows2.png'


const Navbar = () => {
    return (
        <>
            <Nav>
                <NavLink to='/'>
                    <img src={Logo} width="120" height="120" alt='logo' />
                </NavLink>
                <Bars />
                <NavMenu>
                    <NavLink to="/home">
                        HOME
                    </NavLink>
                    <NavLink to="/resorts" >
                        RESORTS
                    </NavLink>
                    <NavLink to="/about" >
                        ABOUT US
                    </NavLink>
                    <NavLink to="/contact" >
                        CONTACT US
                    </NavLink>
                </NavMenu>
                <NavBtn>

                </NavBtn>
            </Nav>
        </>
    )
}

export default Navbar
