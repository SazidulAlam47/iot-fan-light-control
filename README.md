# IoT Home Automation Project with NodeMCU ESP8266
    
<p>Welcome to the official GitHub repository for the IoT Fan and Light Control project. This project harnesses advanced technology, utilizing the NodeMCU ESP8266 and a relay module to exert precise control over a room's lighting and ceiling fan. The project's control interface is conveniently accessible through a responsive web application (Web App), providing users with seamless management of their environment.</p>

<p>What sets this project apart is its integration with the Blynk cloud platform, which not only stores device state data but also empowers users with remote control capabilities from anywhere in the world. Whether you're at home or halfway around the globe, you can effortlessly manage your fan and light settings through the intuitive Web App.</p>

<p>But the innovation doesn't stop there. In addition to the Web App interface, this project features a cutting-edge integration with Google Assistant through IFTTT. Voice commands become your control tool, allowing you to operate your fan and light simply by speaking to your smart assistant. This fusion of IoT technology and voice control enhances the convenience and accessibility of your living space.</p>

<h2>Features</h2>
<ul>
    <li>Control fan and light remotely through a web interface.</li>
    <li>Seamless integration with Google Assistant for voice control.</li>
    <li>Utilizes the NodeMCU ESP8266 and relay module for IoT functionality.</li>
    <li>Real-time status updates using Blynk cloud for on/off state.</li>
    <li>Easy-to-understand code for both the ESP8266 and the web interface.</li>
    <li>Web application built with VoltBuilder.</li>
    <li>Video demonstration of the project in action.</li>
</ul>

<h2>Project Components</h2>
<ul>
    <li>NodeMCU ESP8266</li>
    <li>Relay Module</li>
    <li>Web App for control</li>
    <li>Blynk Cloud integration</li>
</ul>

<h2>Getting Started</h2>
<ol>
    <li><strong>Hardware Setup</strong>: Begin by establishing the hardware configuration. Connect the NodeMCU ESP8266 to the relay module and the fan/light as shown in the diagram below</li>
    <li><strong>Blynk Cloud Setup</strong>: Proceed to set up your Blynk Cloud account by visiting the official <a href="https://www.blynk.io/" target="_blank">Blynk</a> website. Create your account, establish your IoT template and project, and then generate your unique Blynk Automation Token.</li>
    <li><strong>ESP8266 Code Configuration</strong>: Access the ESP8266 code, situated within the <code>/esp8266_code</code> directory. Within this code, replace the Blynk Automation Token with your uniquely generated token, and additionally, provide the SSID and Password of your wireless router. Once this code customization is complete, proceed to upload the modified code to your NodeMCU ESP8266 utilizing the Arduino IDE.</li>
    <li><strong>Web App</strong>: For the web application component, upload the provided web app code found in the <code>/web_app_code</code> directory to VoltBuilder. This process will convert the web interface into a native application. Ensure you provide your Blynk Automation Token within the Blynk API in the JavaScript code during this step.</li>
</ol>

<h2>Connection Diagram</h2>
<img src="connection_diagram.png" alt="Connection Diagram">

<h2>Code Structure</h2>
<ul>
    <li><code>/esp8266_code</code>: Contains the Arduino sketch for the NodeMCU ESP8266.</li>
    <li><code>/web_app_code</code>: Includes the HTML, CSS, and JavaScript files for the web App.</li>
</ul>

<h2>Web Application (Powered by VoltBuilder)</h2>
<p>The web application for controlling the fan and light in this project was built using <a href="https://volt.build/" target="_blank">VoltBuilder</a>. VoltBuilder is a powerful tool for creating cross-platform web applications from your HTML, CSS, and JavaScript code. It allows you to easily package and deploy your web app on various platforms, making it accessible to a wider audience.</p>

<h2>Google Assistant Integration</h2>
<p>Enhance the convenience and functionality of your IoT Fan and Light Control project by seamlessly integrating it with Google Assistant. With the power of voice commands, you can control your fan and light effortlessly. Here's how to set it up:</p>

<ol>
    <li><strong>IFTTT Account</strong>: Ensure you have an active account on <a href="https://ifttt.com/" target="_blank">IFTTT</a> (If This Then That).</li>
    <li><strong>Blynk API Key</strong>: Retrieve your Blynk API key from your Blynk cloud account, which is essential for communication with your IoT devices.</li>
    <li><strong>Google Assistant Applet</strong>: Create custom applets in IFTTT, connecting Google Assistant to your Blynk-based IoT project. Set up voice triggers and the Blynk API Webhook to control the fan and light.</li>
    <li><strong>Voice Control</strong>: Once the integration is complete, simply use voice commands with Google Assistant to activate or deactivate the fan and light, enhancing the accessibility and ease of use of your IoT solution.</li>
</ol>

<p>This integration opens up exciting possibilities for hands-free control of your environment, making your IoT project even more versatile and user-friendly.</p>


<h2>Video Demonstration</h2>
<p>Watch the video below to see the project in action:</p>

<iframe width="324" height="576" src="https://www.youtube.com/embed/8VW1l3-9EXs" title="My first IoT Project | Light &amp; Fan Control with ESP8266 and Relay" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

<h2>Contributing</h2>
<p>If you'd like to contribute to this project or report issues, please open an issue or submit a pull request on the GitHub repository.</p>

<h2>Acknowledgments</h2>
<p>I would like to acknowledge the following for their contributions to this project:</p>
<ul>
    <li><a href="https://www.blynk.io/" target="_blank">Blynk</a> - for providing a robust platform for IoT device control and data storage.</li>
    <li><a href="https://volt.build/" target="_blank">VoltBuilder</a> - for making the development and deployment of the web application seamless and efficient.</li>
</ul>