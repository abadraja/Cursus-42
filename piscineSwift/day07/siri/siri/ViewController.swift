//
//  ViewController.swift
//  siri
//
//  Created by Alen Badrajan on 4/26/17.
//  Copyright © 2017 abadraja. All rights reserved.
//

import UIKit
import RecastAI
import ForecastIO

class ViewController: UIViewController {

    @IBOutlet weak var textField: UITextField!
    @IBOutlet weak var label: UILabel!
    
    
    var bot : RecastAIClient?

    @IBAction func textField(_ sender: UITextField)
    {
        print("poop")
    }
    @IBAction func button(_ sender: UIButton)
    {
        
    }
    
    let client = DarkSkyClient(apiKey: "f1193b5ce124faf9ebe912056d9568d0")

    override func viewDidLoad() {
        super.viewDidLoad()
        //forecast
        self.bot = RecastAIClient(token : "qA3il0iokaF0UTmYAy0m3vv5")
//        makeRequest()
    }

    func makeRequest()
    {
        //Call makeRequest with string parameter to make a text request
        self.bot?.textRequest("Hello", successHandler: {_ in 
            print("yo man 1")
        }, failureHandle: {_ in 
            print("fail man")
        })
        self.bot?.textConverse("poop", successHandler: { (ConverseResponse) in
            print("yo man")
        }, failureHandle: { (Error) in
            print("error")
        })
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

