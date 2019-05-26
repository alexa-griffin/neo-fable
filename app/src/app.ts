import Application from "./application/Application"
import Test from "./layers/Test"


const app: Application = new Application()

const defaultLayer: Test = new Test()

app.pushLayer(defaultLayer)

app.init()
app.start()