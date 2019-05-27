import Layer from "../application/Layer"


export default class Test extends Layer {
  constructor() {
    super()
  }

  onMount() {
    this.addStateListener("data", (o, n) => {
      console.log("data changed")
    })
    this.addStateListener("num", (o, n) => {
      console.log("num changed")
    })
    this.addStateListener("data.kevin", (o, n) => {
      console.log("kevin changed")
    })
    this.addStateListener("data.kevin.name", (o, n) => {
      console.log("name changed")
    })
  }

  onUpdate() {
    this.ctx.fillRect(20, 20, 100, 100)
    this.setState({ 
      num: 1,
      ["data.kevin.name"]: "not kevin"
    })
  }
}