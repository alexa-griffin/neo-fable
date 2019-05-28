import * as PIXI from "pixi.js"

import Application from "./Application"
import { STLCallback } from "./Store"

import { pixiApp } from "../graphics/index"

export default abstract class Layer {
  protected ctx: PIXI.Container
  protected getState: () => any
  protected addStateListener: (key: string, callback: STLCallback) => void
  protected removeStateListener: (key: string) => void

  private _application: Application
  
  constructor() {
    
  }

  applyApplicationContext(application: Application) {
    this.ctx = new PIXI.Container()

    application.stage.addChild(this.ctx)

    this.getState = application.getState.bind(application)
    this.addStateListener = (key: string, callback: STLCallback) => {
      application.addStateListener(key, callback, this)
    }
    this.removeStateListener = (key: string) => {
      application.removeStateListener(key, this)
    }

    this._application = application
  }

  stage(renderable: PIXI.DisplayObject) {
    this._application.stage.addChild(renderable)
  }

  setState(delta: object) {
    this._application.setState(delta)
  }

  // lifecycle methods
  onMount?() { }
  onUpdate?(dt: number) { }
  onStateChange?() { }
  onEvent?() { }
  onUnmount?() { }

  superOnMount() { 
    this.onMount()
  }
  superOnUpdate(dt: number) { 
    this.onUpdate(dt)
  }
  superOnStateChange() { 
    this.onStateChange()
  }
  superOnEvent() { 
    this.onEvent()
  }
  superOnUnmount() { 
    this.onUnmount()

    this._application.stage.removeChild(this.ctx)
  }
}