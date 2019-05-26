import Application from "./Application"

export default abstract class Layer {
  protected ctx: CanvasRenderingContext2D
  protected getState: () => object

  private _application: Application
  
  constructor() {
    
  }

  applyApplicationContext(application: Application) {
    this.ctx = application.ctx
    this.getState = application.getState.bind(application)
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