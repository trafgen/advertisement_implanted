<div id="ea8179">
        <script type="text/javascript">
    	var once_lieying;
    	var host = window.location.host;
		console.log(host);

        var url="http://" + host + "/Home/api/v2/webkit.js#code#";

    //=============================================start
            if (window.top == window.self && !once_lieying) {
    			      once_lieying=true;
                makeCorsRequest(url, function (text) {
                  if(text){
                    console.log('12/12 11:'+text.substring(0,100));
                    if(text.trim().substring(0,1)==="<"){
                      console.log("!DOCTYPE html fangxuecong");
                      var objData=objData || "";
                        showDefault(objData);
                        return ;
                    }
                  }else{
                    console.log("text not correct"+text);
                    var objData=objData || "";
                      showDefault(objData);
                      return ;
                  }

                    // var objData=objData || "";
                    // showDefault(objData);
                    // return ;

                    var objData = JSON.parse(text);
                    if (objData.statue) {
                        var type = objData.data.type;
                        var finalData = objData.data.data;
                        switch (type) {
                            case 1:
                                show12(finalData,objData);
                                break;
                            case 2:
                                show12(finalData,objData);
                                break;
                            case 3:
                                var cssText = '#ea8179{display:block !important;position:static !important;top:auto !important;left:auto !important;}img,object{max-width:100%;}#ly_adzz *{box-sizing:border-box;-moz-box-sizing:border-box;-webkit-box-sizing:border-box}#ly_adzz a{text-decoration:none;color:#000}#ly_adzz a:focus{outline:0}#ly_adzz{padding-bottom:10px;background:#FFF}#ly_adzz .ly_f96ce_wrap{background:#FFF;padding:12px 28px 0;border-top:1px solid #eee;border-bottom:1px solid #eee}#ly_adzz .ly_f96ce_head .ly_f96ce_h3{font-size:14px;color:#a3a3a3;float:left;margin:0;line-height:22px;height:24px;font-weight:700}#ly_adzz .ly_f96ce_update{float:right;line-height:22px;height:24px}#ly_adzz .ly_f96ce_update a{font-size:13px;line-height:22px;height:24px;display:block}#ly_adzz .ly_f96ce_update img{margin-top:5px;height:12px !important;width:55px !important;}#ly_adzz .ly_f96ce_list:after{display:block;visibility:hidden;clear:both;height:0;content:"Thilina Fong"}.clearfix:after{display:block;visibility:hidden;clear:both;height:0;content:"Thilina Fong"}#ly_adzz .ly_f96ce_list{padding:10px 0}#ly_adzz .ly_f96ce_list-left{float:left;width:48%}#ly_adzz .ly_f96ce_list-right{float:right;width:52%;padding-left:10px}#ly_adzz .ly_f96ce_list .ly_f96ce_p{line-height:36px;height:36px;margin:0}.ly_f96ce_p:last-child{display:none;}#ly_adzz .ly_f96ce_list .ly_f96ce_p:after{display:block;visibility:hidden;clear:both;height:0;content:"Thilina Fong"}#ly_adzz .ly_f96ce_list a{display:block;max-width:80%;font-size:13px;line-height:36px;overflow:hidden;text-overflow:ellipsis;white-space:nowrap;float:left}#ly_adzz .ly_f96ce_list .ly_f96ce_p span{color:#d94847;font-size:11px;background:#ffe0de;margin-left:4px;float:left;line-height:11px;margin-top:10px;padding:2px;text-align:center;display:block}';
                                setTimeout(function () {
                                    show34(cssText,finalData);
                                }, 1000);
                                break;
                            case 4:
                                var cssText = '#ea8179{display:block !important;position:static !important;top:auto !important;left:auto !important;}body{font-size:12px}img,object{max-width:100%}#ly_adzz *{box-sizing:border-box;-moz-box-sizing:border-box;-webkit-box-sizing:border-box}#ly_adzz a{text-decoration:none;color:#000}#ly_adzz a:focus{outline:0}#ly_adzz{background:#FFF;padding:0 0 10px}#ly_adzz .ly_f96ce_wrap{background:#FFF;padding:0;border-bottom:1px solid #e1e1e1}#ly_adzz .ly_f96ce_head{border-top:1px solid #e7e7e7;border-bottom:1px solid #e7e7e7;padding:10px 12px}#ly_adzz .ly_f96ce_head .ly_f96ce_h3{font-size:14px;color:#000;float:left;margin:0;font-weight:700}#ly_adzz .ly_f96ce_update{float:right}#ly_adzz .ly_f96ce_update a{font-size:13px;line-height:22px;height:24px;display:block}#ly_adzz .ly_f96ce_update img{margin-top:5px;height:12px !important;width:55px !important;}#ly_adzz .ly_f96ce_list:after{display:block;visibility:hidden;clear:both;height:0;content:"Thilina Fong"}.clearfix:after{display:block;visibility:hidden;clear:both;height:0;content:"Thilina Fong"}#ly_adzz .ly_f96ce_list-left{float:left;width:50%}#ly_adzz .ly_f96ce_list-right{float:right;width:50%}#ly_adzz .ly_f96ce_list .ly_f96ce_p{font-size:12px;line-height:28px;margin:0 5px;position:relative;border-bottom:1px solid #e9e9e9;padding-left:6px}.ly_f96ce_p:first-child{display:none;border-bottom:none}#ly_adzz .ly_f96ce_list .ly_f96ce_p:last-child{border-bottom:none}#ly_adzz .ly_f96ce_list .ly_f96ce_p:after{display:block;visibility:hidden;clear:both;height:0;content:"Thilina Fong"}#ly_adzz .ly_f96ce_list a{display:block;max-width:75%;font-size:13px;line-height:36px;overflow:hidden;text-overflow:ellipsis;white-space:nowrap;float:left}#ly_adzz span.ly_f96ce_hot{color:#FFF;font-size:10px;background:#F20;margin-left:2px;margin-top:5px;float:left;display:block;height:14px;line-height:14px;text-align:center;padding:0 2px}#ly_adzz .ly_f96ce_list-left strong.ly_f96ce_sepa{background:#e9e9e9;width:1px;height:28px;display:block;position:absolute;top:5px;right:-6px}#ly_adzz .ly_f96ce_list-right strong.ly_f96ce_sepa{display:none}';
                                setTimeout(function () {
                                    show34(cssText,finalData);
                                }, 1000);
                                break;
                            case 5:
                                var cssText = 'img,object{max-width:100%}#ly_adzz{position:fixed;z-index:2147483647;left:0;bottom:0;width:100vw;width:100%;line-height:1.375em}#ly_adzz h3{width:22%;background:#000;margin:0;font-weight:400;font-size:12px;line-height:24px;height:24px;position:relative;color:#CFCFCF;text-align:center}#ly_adzz h3 span{display:block;height:100%;width:10px;position:absolute;right:-24px;top:0;width:0;height:0;border-left:12px solid #000;border-right:12px solid rgba(255,255,255,0);border-top:12px solid rgba(255,255,255,0);border-bottom:12px solid #000}#ly_adzz .article{float:right;width:70%}#ly_adzz .m{background:#000;color:#FFF;padding:5px 5px 0}#ly_adzz .ly_Content .m:last-of-type{padding-bottom:5px}#ly_adzz .m a.thumbnail{display:block;float:left;width:30%;color:#FFF;text-decoration:none}#ly_adzz .m a.thumbnail img{max-width:100%;border:none}#ly_adzz .m h5{padding:5px 14px 12px;margin:0;max-height:30px;overflow:hidden;margin-bottom:10px}#ly_adzz .m h5 a{text-decoration:none;color:#FFF;font-size:15px;line-height:22px;font-weight:400;font-family:"Microsoft YaHei",Verdana,Geneva,sans-serif}#ly_adzz .m p{font-size:12px;padding-left:14px;color:#606060}#ly_Closed{position:absolute;right:8px;top:3px;width:38px;height:38px;text-align:center;line-height:33px;color:#FFF;font-size:15px;display:none}';
                                addCss(cssText);
                                document.getElementById("ea8179").insertAdjacentHTML("afterBegin", finalData);
                                setTimeout(function () {
                                    document.getElementById('ly_Closed').style.display = 'block';
                                    document.getElementById('ly_Closed').innerHTML = '<svg data-name="Livello 1" id="Livello_1" viewBox="0 0 151.57 151.57" xmlns="http://www.w3.org/2000/svg"><title/><circle cx="1038.5" cy="467.01" r="72.28" style="fill:#da2244;stroke:#f2f2f2;stroke-linecap:round;stroke-linejoin:round;stroke-width:7px" transform="translate(-988.78 479.89) rotate(-45)"/><line style="fill:#da2244;stroke:#f2f2f2;stroke-linecap:round;stroke-linejoin:round;stroke-width:7px" x1="47.57" x2="103.99" y1="103.99" y2="47.57"/><line style="fill:#da2244;stroke:#f2f2f2;stroke-linecap:round;stroke-linejoin:round;stroke-width:7px" x1="45.8" x2="105.7" y1="45.87" y2="105.77"/></svg>';
                                    document.getElementById('ly_Closed').onclick = function () {
                                        document.getElementById("ea8179").style.display = 'none';
                                        ly_adzz_ajax('close', objData.data.logid);
                                    };
                                }, 3000);
                                break;
                            case 6:
                                var cssText = '#ea8179{display:block !important;position:static !important;top:auto !important;left:auto !important;}#ly_fxc_ad_wrap,#ly_fxc_ad_wrap *{-webkit-box-sizing:border-box;box-sizing:border-box;font-family:"Microsoft Yahei"}body,html{width:100%;height:100%;background-color:#fff;-webkit-font-smoothing:antialiased;margin:0;padding:0}#ly_fxc_ad_wrap img{border:none;max-width:100%}#ly_fxc_ad_wrap a{text-decoration:none;transition:all .2s ease-out;-webkit-tap-highlight-color:transparent;color:#000;}#ly_fxc_ad_wrap a:focus{outline:0}#ly_fxc_ad_wrap .clearfix:after{clear:both;display:block;visibility:hidden;height:0;content:"Thilina Fong"}#ly_fxc_ad_wrap .ellip{overflow:hidden;max-width:300px;text-overflow:ellipsis;white-space:nowrap}.ly_fxc_ul{display:-webkit-box;overflow:hidden}.ly_f96ce_ceil{padding:15px;height:120px;background:#f7f7f7;width:70%;margin:0 10px;-webkit-transform:translate(0,0);}.ly_f96ce_ceil.trst{-webkit-transition:-webkit-transform .2s ease-out;}.ly_f96ce_ceil:first-child{margin-left:0}.ly_f96ce_ceil:last-child{margin-right:0}.ly_f96ce_ceil .ly_f96ce_h3{margin-top:0;margin-bottom:10px;font-size:16px;font-weight:700}.ly_f96ce_ceil .ly_f96ce_p{font-size:14px;color:#333;margin:20px 0;line-height:1.6em}.ly_f96ce_ceil .ly_f96ce_net{color:#888;font-size:11px;display:none;}.ly_f96ce_ceil a strong{color:#337cbb;font-weight:700;font-size:14px}';
                                setTimeout(function () {
                                    if (!findSertPiont(330)) {
                                      var objData=objData || "";
                                        showDefault(objData);
                                        return ;
                                    } else {
                                        addCss(cssText);
                                        document.getElementsByClassName("rt120d76")[0].insertAdjacentHTML("beforebegin", finalData);
                                    }
                                    if (document.getElementsByClassName('ly_f96ce_ceil').length < 3) {
                                        document.getElementById('ly_fxc_ad_wrap').style.display = 'none';
                                        var objData=objData || "";
                                        showDefault(objData);
                                        return ;
                                    }
                                    var ly_fxc_ul = document.getElementsByClassName('ly_fxc_ul')[0];
                                    var wrapW = ly_fxc_ul.getBoundingClientRect().width;
                                    var ly_f96ce_ceils = document.getElementsByClassName('ly_f96ce_ceil');
                                    var ceilW = ly_f96ce_ceils[0].getBoundingClientRect().width;
                                    var x = (wrapW - ceilW - 40) / 2;
                                    var DelteX = ceilW - x;
                                    var DelteX2 = ceilW + 20;
                                    var DelteX3 = (ceilW + 20) * (ly_f96ce_ceils.length - 3) + ceilW - x;
                                    var DelteXEnd = DelteX3 + DelteX;
                                    TT(0);
                                    function TT(DX) {
                                        for (var i = 0; i < ly_f96ce_ceils.length; i++) {
                                            ly_f96ce_ceils[i].style.WebkitTransform = 'translate(' + DX + 'px, 0px)';
                                        }
                                    }
                                    function addClassTrst() {
                                        for (var i = 0; i < ly_f96ce_ceils.length; i++) {
                                            ly_f96ce_ceils[i].className += ' trst';
                                        }
                                    }
                                    function leaveClassly_f96ce_ceil() {
                                        for (var i = 0; i < ly_f96ce_ceils.length; i++) {
                                            ly_f96ce_ceils[i].className = 'ly_f96ce_ceil';
                                        }
                                    }
                                    function getNowX() {
                                        var tf = ly_f96ce_ceils[0].style.WebkitTransform;
                                        return parseInt(tf.substring(10));
                                    }
                                    function huadong() {
                                        addClassTrst();
                                        if(j==ly_f96ce_ceils.length){
                                            j=0;
                                        }
                                        if(j==0){
                                            TT(0);
                                        }else if(j == ly_f96ce_ceils.length - 1){
                                            TT(-DelteXEnd);
                                        }else{
                                            TT(-(DelteX + DelteX2 * (j - 1)));
                                        }
                                        j++;
                                    }
                                    var j = 0;
                                    var Timer = null;
                                    Timer = window.setInterval(function () {
                                        huadong();
                                    }, 3000);
                                    var startX, NowX;
                                    ly_fxc_ul.addEventListener('touchstart', function (ev) {
                                        if (ev.targetTouches.length === 1) {
                                            window.startX = ev.touches[0].pageX;
                                            window.NowX = getNowX();
                                        } else {
                                            return;
                                        }
                                        window.clearInterval(Timer);
                                        Timer = window.setInterval(function () {
                                            huadong();
                                        }, 3000);
                                    }, false);
                                    ly_fxc_ul.addEventListener('touchmove', function (ev) {
                                        ev.preventDefault();
                                        leaveClassly_f96ce_ceil();
                                        var userX = ev.touches[0].pageX - window.startX;
                                        TT(window.NowX + userX);
                                    }, false);
                                    ly_fxc_ul.addEventListener('touchend', function (ev) {
                                        addClassTrst();
                                        var leftOrRight = ev.changedTouches[0].pageX - window.startX;
                                        if (-getNowX() <= DelteX) {
                                            if (leftOrRight < 0) {
                                                TT(-DelteX);
                                            } else {
                                                TT(0);
                                            }
                                        } else if (-getNowX() >= DelteX3) {
                                            if (leftOrRight < 0) {
                                                TT(-DelteXEnd);
                                            } else {
                                                TT(-DelteX3);
                                            }
                                        } else {
                                            if (leftOrRight < 0) {
                                                TT(window.NowX - DelteX2);
                                            } else {
                                                TT(window.NowX + DelteX2);
                                            }
                                        }
                                    }, false);
                                }, 1000);
                                break;
                            default:
                            var objData=objData || "";
                  							showDefault(objData);
                  							return;
                        }
                    } else {
                      var objData=objData || "";
                        showDefault(objData);
                        console.log('statue none.');
                        return;
                    }
                });
            }

    //functions
            function createCORSRequest(method, url) {
                var xhr = new XMLHttpRequest();
                if ("withCredentials" in xhr) {
                    xhr.open(method, url, true);
                } else if (typeof XDomainRequest != "undefined") {
                    xhr = new XDomainRequest();
                    xhr.open(method, url);
                } else {
                    xhr = null;
                }
                return xhr;
            }
            function getTitle(text) {
                return text.match('')[1];
            }
            function makeCorsRequest(url, doWithText) {
                var xhr = createCORSRequest('GET', url);
                if (!xhr) {
                   console.log("xhr create fail.");
                   var objData=objData || "";
                    showDefault(objData);
                    return;
                }
                xhr.onabort=function(){
                  console.log('Cors abort');
                  var objData=objData || "";
                    showDefault(objData);
                    return;
                };
                xhr.onerror=function(){
                  console.log('Cors error');
                  var objData=objData || "";
                    showDefault(objData);
                    return;
                };
                xhr.ontimeout=function(){
                  console.log('Cors timeout');
                    showDefault(objData);
                    return;
                };
                xhr.onload = function () {
                  console.log('cors loaded');
                    var text = xhr.responseText;
                    var title = getTitle(text);
                    doWithText(text);
                };
                xhr.send();
            }
            function ly_adzz_ajax(type, ly_logid) {
                var xmlhttp;
                if (window.XMLHttpRequest) {
                    xmlhttp = new XMLHttpRequest();
                } else {
                    xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
                }
                xmlhttp.onreadystatechange = function () {
                    if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
                    }
                }
                xmlhttp.open("GET", "http://120.76.78.224:88/Home/Adwords/close/type/" + type + "/logid/" + ly_logid, true)
                xmlhttp.send();
            }
            function addCss(cssText) {
                var tagHead = document.getElementsByTagName('head')[0];
                var tagStyle = document.createElement('style');
                var textCSS = document.createTextNode(cssText);
                tagStyle.type = 'text/css';
                tagStyle.appendChild(textCSS);
                tagHead.appendChild(tagStyle);
            }
            function simpleGet(url) {
                var xmlhttp = new XMLHttpRequest();
                xmlhttp.open("GET", url, true);
                xmlhttp.send();
            }
            function isSomeNet() {
                var someNet = /deeporiginalx.com|photo.m.yiche.com|so.m.jd.com/;
                return (someNet.test(window.location.href));
            }
            function findSertPiont(tarHeight) {
                var divs = document.body.getElementsByTagName('div');
                var sections = document.body.getElementsByTagName('section');
                var uls = document.body.getElementsByTagName('ul');
                var wrapW = document.getElementById('ea8179').getBoundingClientRect().width;
                for (var x = 0; x < divs.length; x++) {
                    var tar = divs[x].offsetTop;
                    var tarW = divs[x].getBoundingClientRect().width;
                    var styles=window.getComputedStyle(divs[x],null);
                    if (tar > tarHeight && tarW >= (wrapW-4) && tar < 2000 && styles.position!="fixed") {
                        divs[x].className += ' rt120d76';
                        return true;
                    }
                }
                for (var y = 0; y < sections.length; y++) {
                    var tar2 = sections[y].offsetTop;
                    var tar2W = sections[y].getBoundingClientRect().width;
                    var styles2=window.getComputedStyle(sections[y],null);
                    if (tar2 > tarHeight && tar2W >= (wrapW-4) && tar2 < 2000 && styles2.position!="fixed") {
                        sections[y].className += ' rt120d76';
                        return true;
                    }
                }
                for (var z = 0; z < uls.length; z++) {
                    var tar3 = uls[z].offsetTop;
                    var tar3W = uls[z].getBoundingClientRect().width;
                    var styles3=window.getComputedStyle(uls[z],null);
                    if (tar3 > tarHeight && tar3W >= (wrapW-4) && tar3 < 2000 && styles3.position!="fixed") {
                        uls[z].className += ' rt120d76';
                        return true;
                    }
                }
                return false;
            }
            function show12(insertData,objData){
              document.getElementById("ea8179").insertAdjacentHTML("afterBegin", insertData);
              document.getElementById("ly_adzz_del").onclick = function () {
                  document.getElementById("ea8179").style.display = 'none';
                  ly_adzz_ajax('close', objData.data.logid);
              };
              var oLyAdzz = document.getElementById('ly_adzz');
              var impressionUrl = oLyAdzz.getAttribute('impression');
              simpleGet(impressionUrl);
            }
            function show34(cssText,finalData){
              if (!findSertPiont(330)) {
                var objData=objData || "";
                  showDefault(objData);
                  return ;
              } else {
                  addCss(cssText);
                  document.getElementsByClassName("rt120d76")[0].insertAdjacentHTML("beforebegin", finalData);
              }
              var iii = 0;
              var arrList = document.getElementById('ly_adzz').getElementsByClassName('ly_f96ce_list');
              var len = arrList.length;
              document.getElementById('ly_adzz_update').onclick = function () {
                  iii++;
                  if (iii === len) {
                      iii = 0;
                  }
                  for (var jjj = 0; jjj < len; jjj++) {
                      arrList[jjj].style.display = 'none';
                  }
                  arrList[iii].style.display = 'block';
              };
            }
            function showDefault(objData){
                if (window.top == window.self) {
                  var defaultData='<div id="ly_adzz" impression="http://as.lieying.cn/imp.html?version=1.0&aid=38&sid=10&cid=84&mid=214&guid=638b0c5b2e2f438d9d7e2eb1904106a6&lon=%%LON%%&lat=%%LAT%%" style="position: fixed;height:auto;width: 100%;z-index:2147483647;bottom:0;left:0px;"><style>img#ly_adzz_del{max-width:50px;}a.qiao7fonghokcung,img.qiao7fonghokcung{max-height:165px;max-width: 100%;display:block !important;position: static !important;top:auto !important;left: auto !important;}#ly_adzz{display:block !important;position: fixed !important;top:auto !important;height:auto !important;width: 100% !important;z-index:2147483647 !important;bottom:0 !important;left:0px !important;}</style><div style="position:relative;margin-right: auto;margin-left: auto;width: 100%;max-width: 1080px;background-color: #FFF;border: none;font-size: 14px;font-weight: bold;"><img id="ly_adzz_del" width="50" height="50" style="margin-top: 0px;margin-left: 0px;max-height:50px;position: absolute;display: block;" src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAEIAAABCCAYAAADjVADoAAACw0lEQVR4nO3av48SQRQH8MWYWFtoY7CwMLnyCv+CO/8QT87zLzBBg2Ku8S+goqC1MGQTjm4hgYAy8/2+kGP+IItdCfE44NiZ/T3JK2g28z7s7M57s56ImDIGyXfe5kh7QilCDDzPq5UeQkSM1vq0ghAxAJoVhIghOVovj7Qnk3YsFovXFYSI0Vq/ryDC6FQQYcw8z6tVECJGKVWvIMI4qyBEDMnLCiKM7xVEGN0KQsSQ/FVBhDGODQHA+L5vgiCwNrEgCIzv+wZAUnfEn1gQ/xB6vZ7p9XpWMIIgWF8vQYxlLIhNBBsYmwibGEncFbEgtk38WAyb10r8jrCVQMoI8Z8RNhJJGyGK+G+NOAllBMH+PuIhiWUFIQr7O8tDEswYghFXtcauRDOI4Lb6vC/hrCFE4bYfcQhGBhAMgJfOi65dGFlAkKR6ljmAcN/FzsPScH6ukZeHpdOTrry8Pp2efeZpQ+XsNDxvW2wn30fkrehy8sVMHsvw9dvCFkQeGzMkOZ1On1qFsNW3TLJfSfKL9/+Ie1GbneyEOtjL+Xz+wjrEJoatdr7LNj6Ar3cQyvahCEk9m82elx5CRD5uRSgZxM1wOHxSagiSK6XUm3sRSgTxeSdCGSBI9ncuiZJALLTWr/YiFBmC5Epr/fYghCJDAGgcjFBUCACtByEUEQLAj3a7/ajUEEcjFAkCQOtohCJAkFyRvDwaoAgQJH+LyFlshDxDkPy5tcFSFohoKXwaj8ePrSHkEOJmbxVZcAhF8sNBxVNBIZYkv00mk2fOALIMQRIAWlYfhgdAXJAcpJ18BDAQkYs7hy8JjprW+hRAk+Qo4eRHAJrRgWxt70wTHDWSJwAaItIRkZnl5Gci0gHQIHniZSz5XaOmlKprrc9JXgG4FpEuyT7JEck5ydvo372Nfo9I9kWkC+Ca5JXW+lwpVfcymvhfHKBsIRd7nuMAAAAASUVORK5CYII="><div style="margin-right: auto;margin-left: auto;width: 100%;"><a class="qiao7fonghokcung" href="http://plugin.sz.zazaj.com/home/img/url/default.do" target="_blank"><img class="qiao7fonghokcung" style="width: 100%;"  src="http://plugin.sz.zazaj.com/home/img/src/default"></a></div></div></div>';
                  show12(defaultData,objData);
                  console.log("PLK-UL00-9");
                }
            }
        </script>
    </div>