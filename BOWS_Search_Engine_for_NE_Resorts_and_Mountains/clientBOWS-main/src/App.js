import React from 'react';
import './App.css';
import Navbar from './components/Navbar';
import { BrowserRouter, Routes, Route } from 'react-router-dom'
import Home from './pages';
import About from './pages/about';
import Contact from './pages/contact';
import Mountainfinder from './pages/mountainfinder';
import Resort from './pages/resort';
import NotFoundPage from './pages/notfoundpage';
import Compare from './pages/compare';
import TestZip from './components/Testzip/testzipcode';

function App() {
  return (
    <div className="content">
      <BrowserRouter>
        <Navbar />
        <Routes>
          <Route path='/' element={<Home />} />
          <Route path='/home' element={<Home />} />
          <Route path='/about' element={<About />} />
          <Route path='/contact' element={<Contact />} />
          <Route path='/resorts' element={<Compare />} />
          <Route path='/resort' element={<Resort />} />
          <Route path='/compare' element={<Compare />} />
          <Route path='/testzipcode' element={<TestZip />} />
          <Route path="*" element={<NotFoundPage />} />

        </Routes>
      </BrowserRouter>
    </div>
  );
}

export default App;
