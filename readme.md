# Babylon.js

Getting started? Play directly with the Babylon.js API using our [playground](https://playground.babylonjs.com/). It also contains a lot of samples to learn how to use it.

[![npm version](https://badge.fury.io/js/babylonjs.svg)](https://badge.fury.io/js/babylonjs)
[![Build Status](https://dev.azure.com/babylonjs/ContinousIntegration/_apis/build/status/CI?branchName=master)](https://dev.azure.com/babylonjs/ContinousIntegration/_build/latest?definitionId=14&branchName=master)
[![Average time to resolve an issue](http://isitmaintained.com/badge/resolution/BabylonJS/Babylon.js.svg)](http://isitmaintained.com/project/BabylonJS/Babylon.js "Average time to resolve an issue")
[![Percentage of issues still open](https://isitmaintained.com/badge/open/babylonJS/babylon.js.svg)](https://isitmaintained.com/project/babylonJS/babylon.js "Percentage of issues still open")
![Build size](https://img.shields.io/bundlephobia/minzip/babylonjs)
[![Twitter](https://img.shields.io/twitter/follow/babylonjs.svg?style=social&label=Follow)](https://twitter.com/intent/follow?screen_name=babylonjs)
![Discourse users](https://img.shields.io/discourse/users?server=https%3A%2F%2Fforum.babylonjs.com)

**Any questions?** Here is our official [forum](https://forum.babylonjs.com/).

## CDN

> ⚠️ WARNING: The CDN should not be used in production environments. The purpose of our CDN is to serve Babylon packages to users learning how to use the platform or running small experiments. Once you've built an application and are ready to share it with the world at large, you should serve all packages from your own CDN.

- <https://cdn.babylonjs.com/babylon.js>
- <https://cdn.babylonjs.com/babylon.max.js>


For the preview release, use the following URLs:

- <https://preview.babylonjs.com/babylon.js>
- <https://preview.babylonjs.com/babylon.max.js>

A list of additional references can be found [here](https://doc.babylonjs.com/divingDeeper/developWithBjs/frameworkVers#cdn-current-versions).

## npm

BabylonJS and its modules are published on npm with full typing support. To install, use:

```text
npm install babylonjs --save
```

> alternatively, you can now rely on our [ES6 packages](https://doc.babylonjs.com/setup/frameworkPackages/npmSupport#es6). Using the ES6 version will allow tree shaking among other bundling benefits.

This will allow you to import BabylonJS entirely using:

```javascript
import * as BABYLON from 'babylonjs';
```

or individual classes using:

```javascript
import { Scene, Engine } from 'babylonjs';
```

If using TypeScript, don't forget to add 'babylonjs' to 'types' in `tsconfig.json`:

```json
    ...
    "types": [
        "babylonjs",
        "anotherAwesomeDependency"
    ],
    ...
```

To add a module, install the respective package. A list of extra packages and their installation instructions can be found on the [babylonjs user on npm](https://www.npmjs.com/~babylonjs).

## Usage

See [Getting Started](https://doc.babylonjs.com/#getting-started):

```javascript
// Get the canvas DOM element
var canvas = document.getElementById('renderCanvas');
// Load the 3D engine
var engine = new BABYLON.Engine(canvas, true, {preserveDrawingBuffer: true, stencil: true});
// CreateScene function that creates and return the scene
var createScene = function(){
    // Create a basic BJS Scene object
    var scene = new BABYLON.Scene(engine);
    // Create a FreeCamera, and set its position to {x: 0, y: 5, z: -10}
    var camera = new BABYLON.FreeCamera('camera1', new BABYLON.Vector3(0, 5, -10), scene);
    // Target the camera to scene origin
    camera.setTarget(BABYLON.Vector3.Zero());
    // Attach the camera to the canvas
    camera.attachControl(canvas, false);
    // Create a basic light, aiming 0, 1, 0 - meaning, to the sky
    var light = new BABYLON.HemisphericLight('light1', new BABYLON.Vector3(0, 1, 0), scene);
    // Create a built-in "sphere" shape using the SphereBuilder
    var sphere = BABYLON.MeshBuilder.CreateSphere('sphere1', {segments: 16, diameter: 2, sideOrientation: BABYLON.Mesh.FRONTSIDE}, scene);
    // Move the sphere upward 1/2 of its height
    sphere.position.y = 1;
    // Create a built-in "ground" shape;
    var ground = BABYLON.MeshBuilder.CreateGround("ground1", { width: 6, height: 6, subdivisions: 2, updatable: false }, scene);
    // Return the created scene
    return scene;
}
// call the createScene function
var scene = createScene();
// run the render loop
engine.runRenderLoop(function(){
    scene.render();
});
// the canvas/window resize event handler
window.addEventListener('resize', function(){
    engine.resize();
});
```

## Contributing

If you want to contribute, please read our [contribution guidelines](https://doc.babylonjs.com/contribute/toBabylon) first.

## Documentation

- [Documentation](https://doc.babylonjs.com)
- [Demos](https://www.babylonjs.com/community/)


## Audio Test Project Setup and Testing Guide

Follow all previous Babylon installation steps and then make sure you have the following:

Prerequisites
Ensure that you have the following VSCode extensions installed to facilitate development and testing:

Debugger for Firefox
Docker
ENV
ESLint
Jest
Jest Runner
Microsoft Edge Tools for VSCode
Playwright Test for VSCode
Prettier - Code formatter
TypeScript + Webpack Problem Matcher
webhint
Installation
Install Babylon: Follow the official Babylon installation instructions to set up Babylon locally.
Install Required Extensions: Make sure the VSCode extensions listed in the prerequisites section are installed.
Running Tests
Start the Babylon Local Server:

If the Babylon local server does not start automatically when running the test, manually start it using the following command in the terminal:
npm run serve -w @tools/babylon-server

Run the Playwright Test:
Start the Playwright test in VSCode after the Babylon local server is up and running.
Go to the Testing Tab on the left. Hover the Playwright drop down menu and click the play button (Labeled "Run Test")

Debugging Tips
To view the visual representation with debugger statements:
Click the Play Code button in the browser console.
Wait for the code to finish running or exit out of the browser early if needed.
Troubleshooting
If you encounter any issues while starting the server or running the tests, ensure all dependencies and extensions are correctly installed and updated to their latest versions.
If the test runs into unexpected errors, try restarting VSCode and re-running the steps outlined above.

