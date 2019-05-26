

export default abstract class Layer {
  constructor() {
    
  }

  onMount?() {}
  onUpdate?() { console.log("default update") }
  onUnmount?() {}
  onEvent?() { }
}