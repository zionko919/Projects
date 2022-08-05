import React from 'react';
import emailjs from 'emailjs-com';

//npm install emailjs-com --save

export default function ContactUs() {


    function sendEmail(e) {
        e.preventDefault();

        emailjs.sendForm('service_m0e2fk1', 'BOWStemplate', e.target, 'user_IdY4EaXVpT6tDQT3L7I5U')
            .then((result) => {
                console.log(result.text);
            }, (error) => {
                console.log(error.text);
                //this resets the input text fields

            });
        e.target.reset()

    }

    return (
        <div>
            <h1> Contact Us </h1>
            <div className="form-group">

                <form className="contact-form" onSubmit={sendEmail}>

                    <label>Name</label>
                    <input type="text" required name="name" />

                    <label>Email</label>
                    <input type="email" required name="email" />

                    <label>Message</label>
                    <textarea name="message" required />

                    <input type="submit" value="Send" />
                </form>
            </div>

            <div id="status" className="success" hidden> Success your email has been sent! </div>

            <p className="contact"> IF SUBMIT BUTTON DOES NOT WORK PLEASE CONTACT US DIRECTLY AT beonewiththesnow.uml@gmail.com </p>
        </div>
    )
}