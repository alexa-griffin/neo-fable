import Application from "./Application"
import { STLCallback } from "./Store"


export default abstract class Layer {
  protected ctx: CanvasRenderingContext2D
  protected getState: () => object
  protected addStateListener: (key: string, callback: STLCallback) => void
  protected removeStateListener: (key: string) => void

  private _application: Application
  
  constructor() {
    
  }

  applyApplicationContext(application: Application) {
    this.ctx = application.ctx

    this.getState = application.getState.bind(application)
    this.addStateListener = (key: string, callback: STLCallback) => {
      application.addStateListener(key, callback, this)
    }
    this.removeStateListener = (key: string) => {
      application.removeStateListener(key, this)
    }

    this._application = application
  }

  setState(delta: object) {
    this._application.setState(delta)
  }

  // lifecycle methods
  onMount?() { }
  onUpdate?() { }
  onStateChange?() { }
  onEvent?() { }
  onUnmount?() { }
}