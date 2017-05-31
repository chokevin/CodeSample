import React, {Component} from 'react';
import {Button, Icon, Input} from 'semantic-ui-react'
import logo from './logo.svg';
import './App.css';
import Clock from './Clock.js';

class App extends Component {
    render() {
        return (
            <div className="App">
                <MainPage name={new String("New User")}/>
            </div>
        );
    }
}

function MainPage(props) {
    return (
        <div>
            <div className="App-header">
                <img src={logo} className="App-logo" alt="logo"/>
                <h2>Welcome {props.name}</h2>
            </div>
            <Clock date={new Date()}/>
            <div className="button-inputbox">
                <ButtonExampleAnimated/>
                <NameInputForDashboard/>
            </div>
        </div>
    )
}

const ButtonExampleAnimated = () => (
    <div className="loginbutton">
        <Button animated>
            <Button.Content visible>Next</Button.Content>
            <Button.Content hidden>
                <Icon name='right arrow'/>
            </Button.Content>
        </Button>
    </div>
)

const NameInputForDashboard = () => (<Input placeholder='Insert Username...'/>)

export default App;
