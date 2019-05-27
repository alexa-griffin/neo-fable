import Application from "./Application"
import { STLCallback } from "./Store"


export default abstract class Layer {
  protected ctx: CanvasRenderingContext2D
  protected getState: () => object
  protected addStateListener: (key: string, callback: STLCallback) => void

  private _application: Application
  
  constructor() {
    
  }

  applyApplicationContext(application: Application) {
    this.ctx = application.ctx
    this.getState = application.getState.bind(application)
    this.addStateListener = application.addStateListener.bind(application)

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