//
//  ViewController.swift
//  Kanto
//
//  Created by Alen Badrajan on 4/22/17.
//  Copyright © 2017 abadraja. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

public var region:MKCoordinateRegion?
public var kek = 0
public var geoLoc: [(String,String,Float,Float)] = [
    ("42","Ecole trop style", 48.896557,2.318534),
    ("AcademyPlus","Here I live", 47.038974, 28.824741),
    ("Hell","Don't even try to go here ;)", 46.985579, 28.869975)]

class MyPointAnnotation : MKPointAnnotation
{
    var pinTintColor: UIColor?
}

class ViewController: UIViewController, MKMapViewDelegate, CLLocationManagerDelegate {
    
    @IBOutlet weak var mapView: MKMapView!
    
    var locationManager = CLLocationManager()
    
    override func viewDidLoad()
    {
        super.viewDidLoad()
        
        
        let span:MKCoordinateSpan = MKCoordinateSpanMake(0.01, 0.01)
        
        let myloc0:CLLocationCoordinate2D = CLLocationCoordinate2DMake(CLLocationDegrees(geoLoc[kek].2), CLLocationDegrees(geoLoc[kek].3))
        
        let myloc:CLLocationCoordinate2D = CLLocationCoordinate2DMake(CLLocationDegrees(geoLoc[0].2), CLLocationDegrees(geoLoc[0].3))
        let myloc2:CLLocationCoordinate2D = CLLocationCoordinate2DMake(CLLocationDegrees(geoLoc[1].2), CLLocationDegrees(geoLoc[1].3))
        let myloc3:CLLocationCoordinate2D = CLLocationCoordinate2DMake(CLLocationDegrees(geoLoc[2].2), CLLocationDegrees(geoLoc[2].3))

        let region:MKCoordinateRegion = MKCoordinateRegionMake(myloc0, span)
        
        mapView.setRegion(region, animated: true)
        
        let annotation = MyPointAnnotation()
        let annotation2 = MyPointAnnotation()
        let annotation3 = MyPointAnnotation()
        
        annotation.pinTintColor = .blue
        annotation.coordinate = myloc
        annotation.title = geoLoc[0].0
        annotation.subtitle = geoLoc[0].1
        
        annotation2.pinTintColor = .green
        annotation2.coordinate = myloc2
        annotation2.title = geoLoc[1].0
        annotation2.subtitle = geoLoc[1].1
        
        annotation3.pinTintColor = .black
        annotation3.coordinate = myloc3
        annotation3.title = geoLoc[2].0
        annotation3.subtitle = geoLoc[2].1
        
        mapView.addAnnotation(annotation)
        mapView.addAnnotation(annotation2)
        mapView.addAnnotation(annotation3)
        
//        self.mapView.showsUserLocation = true
//        
//
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
        locationManager.requestWhenInUseAuthorization()
        locationManager.startUpdatingLocation()

//        checkCoreLocationPermission()
    }
//    
    func mapView(_ mapView: MKMapView, viewFor annotation: MKAnnotation) -> MKAnnotationView?
    {
        var annotationView = mapView.dequeueReusableAnnotationView(withIdentifier: "myAnnotation") as? MKPinAnnotationView
        
        if annotationView == nil
        {
            annotationView = MKPinAnnotationView(annotation: annotation, reuseIdentifier: "myAnnotation")
        } else {
            annotationView?.annotation = annotation
        }
        
        if let annotation = annotation as? MyPointAnnotation {
            annotationView?.pinTintColor = annotation.pinTintColor
        }
        
        return annotationView
    }
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation])
    {
        let loc = locations[0]
        let span:MKCoordinateSpan = MKCoordinateSpanMake(0.01, 0.01)
        let myloc:CLLocationCoordinate2D = CLLocationCoordinate2DMake(loc.coordinate.latitude, loc.coordinate.longitude)
        region = MKCoordinateRegionMake(myloc, span)
//        mapView.setRegion(region, animated: true)
        
        self.mapView.showsUserLocation = true
    }
    
    @IBAction func updateButt(_ sender: UIButton)
    {
        mapView.setRegion(region!, animated: true)
//        locationManager.startUpdatingLocation()
    }
    
    @IBAction func segmentControl(_ sender: UISegmentedControl)
    {
        switch (sender.selectedSegmentIndex) {
        case 0:
            mapView.mapType = .standard
        case 1:
            mapView.mapType = .satellite
        default:
            mapView.mapType = .hybrid
        }
    }
    
}

