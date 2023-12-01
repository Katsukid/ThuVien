<!-- acquisitions-search.inc -->
<div id="header_search" role="tablist">
 <div class="tab-content">
 <div id="supplier_search" role="tabpanel" class="tab-pane active">
 <form name="findsupplier" action="/cgi-bin/koha/acqui/booksellers.pl" method="post">
 <div class="form-title">
 <label class="control-label">Tìm kiếm nhà cung cấp</label>
 </div>

 <div class="form-content">
 <input type="text" name="supplier" id="supplier" class="head-searchbox form-control" placeholder="Search vendors" />
 </div>
 <button type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 </div>

 <div id="orders_search" role="tabpanel" class="tab-pane">
 <form action="/cgi-bin/koha/acqui/histsearch.pl" method="post">
 <div class="form-title">
 <label class="control-label">Tìm kiếm đơn hàng</label>
 </div>

 <div class="form-content">
 <input class="form-control" id="title" name="title" placeholder="Nhan đề" size="13" type="text" value="[% title | html %]" />
 <input class="form-control" id="searchsupplier" name="name" placeholder="Nhà cung cấp" size="13" type="text" value="[% name | html %]" />
 <button type="button" class="form-extra-content-toggle"><i class="fa fa-sliders"></i></button>
 <input type="hidden" id="do_search" name="do_search" value="do" />
 </div>
 <button type="submit"><i class="fa fa-arrow-right"></i></button>

 <div class="form-extra-content">
 <div>
 <label for="basket" class="control-label">Giỏ đặt hàng</label>
 <input class="form-control" id="basket" name="basket" placeholder="Giỏ đặt hàng" type="text" />
 </div>
 <div>
 <label for="booksellerinvoicenumber" class="control-label">Số hóa đơn</label>
 <input class="form-control" id="booksellerinvoicenumber" name="booksellerinvoicenumber" placeholder="Số hóa đơn" type="text" />
 </div>
 <div>
 <a href="/cgi-bin/koha/acqui/histsearch.pl">Tìm kiếm nâng cao</a>
 </div>
 </div>
 </form>
 </div>
 </div><!-- /.tab-content -->
 <ul class="nav nav-tabs" role="tablist">
 <li role="presentation" class="active">
 <a aria-controls="supplier_search" aria-expanded="true" class="keep_text" data-toggle="tab" href="#supplier_search" role="tab" title="Tìm kiếm nhà cung cấp"><i class="fa fa-upload"></i> <span class="tab-title">Tìm kiếm nhà cung cấp</span></a>
 </li>
 <li role="presentation">
 <a aria-controls="orders_search" class="keep_text" data-toggle="tab" href="#orders_search" role="tab" title="Tìm kiếm đơn hàng"><i class="fa fa-download"></i> <span class="tab-title">Tìm kiếm đơn hàng</span></a>
 </li>
 </ul>
</div><!-- /#header_search -->
<!-- /acquisitions-search.inc -->
