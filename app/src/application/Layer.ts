import Application from "./Application"

export default abstract class Layer {
  protected ctx: CanvasRenderingContext2D

  constructor() {
    
  }

  applyApplicationContext(application: Application) {
    this.ctx = application.ctx
  }

  // lifecycle methods
  onMount?() {}
  onUpdate?() { }
  onEvent?() { }
  onUnmount?() {}
}