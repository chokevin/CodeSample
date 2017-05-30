import React, {Component} from 'react';
import {Button, Icon} from 'semantic-ui-react'
import logo from './logo.svg';
import './App.css';

class App extends Component {
    render() {
        return (
            <div className="App">
                <div className="App-header">
                    <img src={logo} className="App-logo" alt="logo"/>
                    <h2>Welcome to React</h2>
                </div>
                <p className="App-intro">
                    To get started, edit
                    <code>src/App.js</code>
                    and save to reload.
                </p>
                <ButtonExampleAnimated/>
            </div>
        );
    }
}

const ButtonExampleAnimated = () => (
    <div>
        <Button animated>
            <Button.Content visible>Next</Button.Content>
            <Button.Content hidden>
                <Icon name='right arrow'/>
            </Button.Content>
        </Button>
    </div>
)

export default App;
