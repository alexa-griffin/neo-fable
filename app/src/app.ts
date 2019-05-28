import Application from "./application/Application"
import Test from "./layers/Test"


const app: Application = new Application()

app.pushLayer(new Test())

export { app }